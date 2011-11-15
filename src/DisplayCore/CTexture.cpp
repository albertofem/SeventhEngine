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
	U64 CTexture::m_TextureCounter = 0;

	CTexture::~CTexture()
	{
	}

	CTexture::CTexture(std::string filename)
	{
		m_ResourceFile = filename;
		m_ResourceLoaded = false;
		m_Draw = true;

		// save coords
		SDL_Coords.h = 0;
		SDL_Coords.w = 0;
		SDL_Coords.x = 0;
		SDL_Coords.y = 0;

		// texture static counter
		m_TextureID = m_TextureCounter;
		m_TextureCounter++;
	}

	CTexture::CTexture(const CTexture& lhs)
	{
		m_ResourceLoaded = lhs.m_ResourceLoaded;
		m_ResourceFile = lhs.m_ResourceFile;
		m_Draw = true;

		SDL_Coords = lhs.SDL_Coords;

		// copy textured has the same surface data
		m_Surface = lhs.m_Surface;
	}

	bool CTexture::LoadSurfaceMemory()
	{
		if(m_ResourceLoaded == false)
		{
			// get the texture struct and store the texture in the map
			SDL_Surface* Surface_Temp = NULL;

			if((Surface_Temp = IMG_Load(m_ResourceFile.c_str())) == NULL)
				return false;

			// set alpha for png-like formats
			m_Surface.reset(SDL_DisplayFormatAlpha(Surface_Temp));

			// free old resource
			SDL_FreeSurface(Surface_Temp);

			// set width and height
			SDL_Coords.h = m_Surface->h;
			SDL_Coords.w = m_Surface->w;

			// also set already loaded to true
			m_ResourceLoaded = true;

			m_Draw = false;
		}

		return true;
	}

	void CTexture::Position(S32 pos_x, S32 pos_y)
	{
		SDL_Coords.x = pos_x;
		SDL_Coords.y = pos_y;

		m_Draw = true;
	}

	SDL_Surface* CTexture::GetSurfacePtr()
	{
		LoadSurfaceMemory();

		return m_Surface.get();
	}
}

