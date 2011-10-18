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
		//m_DBufferScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, CDisplayCore::_Screen()->w, CDisplayCore::_Screen()->h, 32);

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

		m_TextureCounter++;

		return texture_id;
	}

	void CTextureManager::RenderTexture(U32 texture_id)
	{
		SDL_Rect temp = m_Textures[texture_id]->getSDLRect();

		// check if the texture is need to draw
		if(m_Textures[texture_id]->needToDraw())
		{
			TRACE("Trying to blit in (%d, %d)", temp.x, temp.y);
			SDL_BlitSurface(m_Textures[texture_id]->getSurfacePtr(), NULL, m_DBufferScreen, &m_Textures[texture_id]->getSDLRect());

			// texture already draw, no need to draw again until next
			// transformation
			m_Textures[texture_id]->SetDraw(false);
		}
	}

	void CTextureManager::TransformTexture(U32 texture_id, STH_Transform &transform)
	{
		m_Textures[texture_id]->Transform(transform);
	}

	void CTextureManager::Render()
	{
		SDL_BlitSurface(m_DBufferScreen, NULL, CDisplayCore::_Screen(), NULL);
	}

	void CTextureManager::CleanScreen()
	{
		if(m_Clean)
			SDL_FillRect(m_DBufferScreen, NULL, 0x000000);

		m_Clean = false;
	}
}
