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
		// textureID temp
		U32 texture_id = m_TextureCounter;

		// create and register the new texture in the texture map
		m_Textures[m_TextureCounter].reset(new CTexture(filename));

		// set new ID in the texture object
		m_Textures[m_TextureCounter]->SetTextureID(texture_id);
		m_TextureCounter++;

		return texture_id;
	}

	void CTextureManager::RenderTexture(U32 texture_id)
	{
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

	void CTextureManager::TransformTexture(U32 texture_id, STH_Transform &transform)
	{
		//TRACE("Final get of transformation on texture ID (%d)", texture_id);
		SDL_Rect old_portion = m_Textures[texture_id]->getSDLRect();

		m_Textures[texture_id]->Transform(transform);

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


	void CTextureManager::Render()
	{
		SDL_BlitSurface(m_DBufferScreen, NULL, CDisplayCore::_Screen(), NULL);
	}

	void CTextureManager::CleanScreen(SDL_Rect* portion = NULL)
	{
		//TRACE("Limpiando porción en (%d, %d), tamaño: %dx%d", portion->x, portion->y, portion->w, portion->h);
		SDL_FillRect(m_DBufferScreen, portion, 0x000000);
	}
}
