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
	}

	CTexture::CTexture(std::string filename, U16 x, U16 y, U16 w, U16 h)
	{
		m_ResourceFile = filename;
		m_ResourceLoaded = false;
		m_Draw = true;

		Tile_Coords.x = x;
		Tile_Coords.y = y;
		Tile_Coords.w = w;
		Tile_Coords.h = h;

		m_TextureType = TEXTURE_TILE;
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

			if(m_TextureType == TEXTURE_TILE)
			{
				ExtractTile(Surface_Temp);
			}
			else
			{
				// set alpha for png-like formats
				m_Surface.reset(SDL_DisplayFormatAlpha(Surface_Temp));
			}

			TRACE("Surface %dx%d", m_Surface->h, m_Surface->w);

			// set width and height
			SDL_Coords.h = m_Surface->h;
			SDL_Coords.w = m_Surface->w;

			// free old resource
			SDL_FreeSurface(Surface_Temp);

			// also set already loaded to true
			m_ResourceLoaded = true;
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

	void CTexture::ExtractTile(SDL_Surface* sfc_origin)
	{
		U32 rmask, gmask, bmask, amask;

		// byte order
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
	#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
	#endif

		// create a surface from scratch
		m_Surface.reset(SDL_CreateRGBSurface(SDL_HWSURFACE, Tile_Coords.w, Tile_Coords.h,
									sfc_origin->format->BitsPerPixel,
									0x00ff0000,
									0x0000ff00,
									0x000000ff,
									(sfc_origin->format->BitsPerPixel == 32 ? 0xff000000 : 0)));

		SDL_SetAlpha(sfc_origin, 0, SDL_ALPHA_OPAQUE);

		if(m_Surface == NULL)
		{
			TRACE("Creating surface tile failed: %s", SDL_GetError());
		}
		else
		{
			TRACE("Blitting surface to tile, %d - %d, %d, %d", Tile_Coords.x, Tile_Coords.y, Tile_Coords.w, Tile_Coords.h);
			// blit surface tile to the new created surface
			SDL_BlitSurface(sfc_origin, &Tile_Coords, m_Surface.get(), NULL);
		}

	}
}

