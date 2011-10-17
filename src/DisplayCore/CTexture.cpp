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

#include "SDL_image.h"

#include "common.h"
#include "DisplayCore/CTexture.h"

namespace Seventh
{
	CTexture::CTexture()
		: m_TextureCoords(-1, -1, -1, -1)
	{

	}

	CTexture::~CTexture()
	{
		SDL_FreeSurface(m_Surface);
	}

	CTexture::CTexture(std::string filename, const TextureCoord& coord)
		: m_TextureCoords(coord.fromX, coord.fromY, coord.toX, coord.toY)
	{
		m_ResourceFile = filename;
		m_ResourceLoaded = false;
		m_Draw = true;
	}

	bool CTexture::loadResource()
	{
		if(m_ResourceLoaded == false)
		{
			// get the texture struct and store the texture in the map
			SDL_Surface* Surface_Temp = NULL;

			if((Surface_Temp = IMG_Load(m_ResourceFile.c_str())) == NULL)
			{
				return false;
			}

			// set alpha for png-like formats
			m_Surface = SDL_DisplayFormatAlpha(Surface_Temp);

			// free old resource
			SDL_FreeSurface(Surface_Temp);

			// set width and height
			m_TextureCoords.width = m_Surface->w;
			m_TextureCoords.height = m_Surface->h;

			// set SDL coord
			SDL_Coords.h = m_TextureCoords.width;
			SDL_Coords.w = m_TextureCoords.height;
			SDL_Coords.x = 0;
			SDL_Coords.y = 0;

			// also set already loaded to true
			m_ResourceLoaded = true;

			m_Draw = false;
		}

		return true;
	}

	void CTexture::Transform(STH_Transform &transform)
	{
		SDL_Coords.x = SDL_Coords.x+transform.move_x;
		SDL_Coords.x = SDL_Coords.x+transform.move_y;

		m_Draw = true;
	}

	SDL_Surface* CTexture::getSurfacePtr()
	{
		loadResource();

		return m_Surface;
	}
}

