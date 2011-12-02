/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.0625
 *
 */

#include "DisplayCore/CDisplayCore.h"
#include "Rendering/CTexture.h"
#include "Rendering/CTextureManager.h"
#include "DisplayCore/CDisplayCore.h"

namespace Seventh
{
	CTextureManager::CTextureManager()
		: m_TextureCounter(1)
	{
	}

	CTextureManager::~CTextureManager()
	{
	}

	U64 CTextureManager::LoadTexture(std::string filename, U64 prev_texture_id)
	{
		U32 texture_id = m_TextureCounter;
		s_DuplicateTexture check_already_loaded = TextureIsLoaded(filename);

		U64 return_id;

		if(prev_texture_id == 0)
		{
			// resource doesnt have previous ID associated
			// we have to give them a new one

			// also check if the resource is already loaded in memory
			if(check_already_loaded.code == 0)
			{
				// resource is not loaded in memory, create it
				m_Textures[texture_id].reset(new CTexture(filename));
				m_LoadedTextures[filename] = texture_id;

				m_TextureRefCounter[texture_id] = 1;

				return_id = texture_id;
			}
			else
			{
				// resource is loaded, check if we have only 1 instance of the resource
				if(m_TextureRefCounter[check_already_loaded.texture_id] == 1)
				{
					// only 1 instance, give a copy and delete old one
					m_Textures[texture_id].reset(new CTexture(*m_Textures[check_already_loaded.texture_id].get()));
					m_Textures.erase(check_already_loaded.texture_id);
				}
				else
				{
					// more than one resource with the same texture, give a copy and increment
					// the reference counter
					m_Textures[texture_id].reset(new CTexture(*m_Textures[check_already_loaded.texture_id].get()));
				}

				return_id = texture_id;
			}

			m_TextureCounter++;

		}
		else
		{
			TRACE("Previous ID detected: %d", prev_texture_id);

			if(check_already_loaded.code == 0)
			{
				TRACE("With prev ID, loading new texture");
				// resource is not loaded in memory, create it
				m_Textures[prev_texture_id].reset(new CTexture(filename));
				m_LoadedTextures[filename] = prev_texture_id;

				m_TextureRefCounter[prev_texture_id] = 1;
			}
			else
			{
				TRACE("Texture has ref counter: %d, texture ID: %d", m_TextureRefCounter[check_already_loaded.texture_id], check_already_loaded.texture_id);

				m_Textures[prev_texture_id].reset(new CTexture(*m_Textures[check_already_loaded.texture_id].get()));

				m_TextureRefCounter[check_already_loaded.texture_id]++;

				TRACE("Copied texture now has reference counter %d", m_TextureRefCounter[check_already_loaded.texture_id]);

				m_TextureRefCounter[prev_texture_id] = m_TextureRefCounter[check_already_loaded.texture_id];
			}

			return_id = prev_texture_id;
		}

		MustRender();

		return return_id;
	}

	U64 CTextureManager::LoadTile(std::string filename, U16 x, U16 y, U16 w, U16 h)
	{
		U32 texture_id = m_TextureCounter;

		m_Textures[m_TextureCounter].reset(new CTexture(filename, x, y, w, h));
		m_TextureCounter++;

		return texture_id;
	}

	void CTextureManager::RenderTexture(U32 texture_id, S32 pos_x, S32 pos_y)
	{
		SDL_Rect old_position = m_Textures[texture_id]->getSDLRect();

		if(old_position.x == pos_x && old_position.y == pos_y)
			return;

		MustRender();

		// change position
		m_Textures[texture_id]->Position(pos_x, pos_y);

		// check for nearby textures
		TextureCollision(texture_id);
	}

	bool CTextureManager::CheckTextureCollision(SDL_Rect* texture1, SDL_Rect* texture2)
	{
		return true;

		// TODO fix the texture collision detection

		if((texture1->x+texture1->w > texture2->x) &&
			texture1->y+texture1->h < texture2->y)
		{
			//TRACE("Colisión confirmada, texture1 (%d, %d) - %dx%d - texture2 (%d, %d) - %dx%d",
			//	texture1->x, texture1->y,
			//	texture1->w, texture1->h,
			//	texture2->x, texture2->y,
			//	texture2->w, texture2->h)
			return true;
		}

		if((texture1->x < texture2->x+texture2->h) &&
			texture2->y < texture2->y+texture2->h)
		{
			return true;
		}

		return false;
	}

	void CTextureManager::TextureCollision(U64 texture_id)
	{
		// check for colliding textures to redraw if any
		// get texture new position
		std::map< U64, boost::shared_ptr<CTexture> >::const_iterator it;

		for(it=m_Textures.begin(); it!=m_Textures.end(); it++)
		{
			if(texture_id != it->first)
			{
				m_Textures[it->first]->SetDraw(true);
			}
		}
	}

	void CTextureManager::HideTexture(U32 texture_id)
	{
		TextureCollision(texture_id);

		m_TextureRefCounter[texture_id]--;

		TRACE("Texture %d, has reference counter: %d", texture_id, m_TextureRefCounter[texture_id]);

		if(!STH_GLOBAL::TEXTURE_PERSISTENT)
		{
			if(m_TextureRefCounter[texture_id] == 0)
			{
				m_LoadedTextures.erase(m_Textures[texture_id]->GetSourceFile());
				m_Textures.erase(texture_id);
			}
		}

		MustRender();
	}

	void CTextureManager::Render()
	{
		if(m_Render)
			RenderMapContainer(m_Textures);

		m_Render = false;
	}

	s_DuplicateTexture CTextureManager::TextureIsLoaded(std::string filename)
	{
		std::map< std::string, U32 >::const_iterator it;

		it = m_LoadedTextures.find(filename);

		s_DuplicateTexture return_info;

		if(it == m_LoadedTextures.end())
		{
			// doesnt exists
			return_info.code = 0;

			TRACE("Texture %s doesnt exists", filename.c_str());
		}
		else
		{
			// texture is found, lets see if it hasnt moved since
			// it was loaded, so we can use exactly the same
			return_info.texture_id = it->second;
			return_info.code = 1;

			TRACE("Texture %s already exists, with ID: %d", filename.c_str(), it->second);
		}

		return return_info;
	}
}
