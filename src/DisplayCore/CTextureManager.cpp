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

	}

	CTextureManager::~CTextureManager()
	{
	}

	U32 CTextureManager::CreateTexture(std::string filename, const TextureCoord& coord)
	{
		// textureID temp
		U32 texture_id = m_TextureCounter;

		// create and register the new texture in the texture map
		m_Textures[m_TextureCounter].reset(new CTexture(filename, coord));

		m_TextureCounter++;

		return texture_id;
	}

	void CTextureManager::RenderTexture(U32 texture_id)
	{
		// check if the texture is need to draw
		if(m_Textures[texture_id]->needToDraw())
		{
			TRACE("Trying to blit.");
			SDL_BlitSurface(m_Textures[texture_id]->getSurfacePtr(), NULL, CDisplayCore::_Screen(), NULL);
		}
	}
}
