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
#include "DisplayCore/CTexture.h"
#include "DisplayCore/CTextureManager.h"
#include "DisplayCore/CDisplayCore.h"

namespace Seventh
{
	CTextureManager::CTextureManager()
		: m_TextureCounter(0)
	{
		//m_DBufferScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, CDisplayCore::_Screen()->w, CDisplayCore::_Screen()->h, 32, rmask, gmask, bmask, amask);
		m_DBufferScreen = SDL_DisplayFormat(CDisplayCore::_Screen());
	}

	CTextureManager::~CTextureManager()
	{
	}

	U32 CTextureManager::CreateTexture(std::string filename)
	{
		S32 check_already_loaded = TextureIsLoaded(filename);

		if(check_already_loaded != -1)
			return check_already_loaded;

		// textureID temp
		U32 texture_id = m_TextureCounter;

		// create and register the new texture in the texture map
		m_Textures[m_TextureCounter].reset(new CTexture(filename));

		// set new ID in the texture object
		m_Textures[m_TextureCounter]->SetTextureID(texture_id);
		m_TextureCounter++;

		// add this texture to already loaded textures
		m_LoadedTextures[filename] = texture_id;

		return texture_id;
	}

	void CTextureManager::RenderTexture(U32 texture_id, S32 pos_x, S32 pos_y)
	{
		PositionTexture(texture_id, pos_x, pos_y);

		// check if the texture is need to draw
		if(m_Textures[texture_id]->needToDraw())
		{
			//TRACE("Getting to render texture ID (%d)", texture_id);
			//TRACE("Trying to blit in (%d, %d)", m_Textures[texture_id]->getSDLRect().x, m_Textures[texture_id]->getSDLRect().y);
			SDL_BlitSurface(m_Textures[texture_id]->getSurfacePtr(), NULL, m_DBufferScreen, &m_Textures[texture_id]->getSDLRect());

			// texture already draw, no need to draw again until next
			// transformation
			m_Textures[texture_id]->SetDraw(false);
		}
	}

	void CTextureManager::PositionTexture(U32 texture_id, S32 pos_x, S32 pos_y)
	{
		//TRACE("Final get of transformation on texture ID (%d)", texture_id);
		SDL_Rect old_portion = m_Textures[texture_id]->getSDLRect();

		// check if the position hanst changed
		if(old_portion.x == pos_x && old_portion.y == pos_y)
		{
			return;
		}

		// change position
		m_Textures[texture_id]->Position(pos_x, pos_y);

		// check for colliding textures to redraw if any
		// get texture new position
		std::map< U32, boost::shared_ptr<CTexture> >::const_iterator it;

		for(it=m_Textures.begin(); it!=m_Textures.end(); it++)
		{
			if(texture_id != it->first)
			{
				if(CheckTextureCollision(&m_Textures[texture_id]->getSDLRect(),
									&m_Textures[it->first]->getSDLRect()))
				{
					m_Textures[it->first]->SetDraw(true);
				}
			}
		}

		// clean only previous portion
		CleanScreen(&old_portion);
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

	void CTextureManager::HideTexture(U32 texture_id)
	{
		SDL_Rect old_portion = m_Textures[texture_id]->getSDLRect();
		CleanScreen(&old_portion);

		m_Textures[texture_id]->SetDraw(false);
	}

	void CTextureManager::Render()
	{
		SDL_BlitSurface(m_DBufferScreen, NULL, CDisplayCore::_Screen(), NULL);
	}

	void CTextureManager::CleanScreen(SDL_Rect* portion = NULL)
	{
		//TRACE("Limpiando porción en (%d, %d), tamaño: %dx%d", portion->x, portion->y, portion->w, portion->h);
		SDL_FillRect(m_DBufferScreen, portion, 0x000000);
	}

	S32 CTextureManager::TextureIsLoaded(std::string filename)
	{
		std::map< std::string, U32 >::const_iterator it;

		it = m_LoadedTextures.find(filename);

		if(it == m_LoadedTextures.end())
		{
			return -1;
		}

		return it->second;
	}
}
