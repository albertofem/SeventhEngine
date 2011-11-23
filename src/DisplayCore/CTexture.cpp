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

		m_Texture = 0;
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
		m_Texture = lhs.m_Texture;
	}

	bool CTexture::LoadSurfaceMemory()
	{
		if(m_ResourceLoaded == false)
		{
			// get the texture struct and store the texture in the map
			SDL_Surface* Surface_Temp = NULL;

			if((Surface_Temp = IMG_Load(m_ResourceFile.c_str())) == NULL)
				return false;

			GLint num_colors;
			GLenum texture_format;

			 // get the number of channels in the SDL surface
			num_colors = Surface_Temp->format->BytesPerPixel;
			if (num_colors == 4)     // contains an alpha channel
			{
				if (Surface_Temp->format->Rmask == 0x000000ff)
							texture_format = GL_RGBA;
					else
							texture_format = GL_BGRA;
			} 
			else if (num_colors == 3)     // no alpha channel
			{
					if (Surface_Temp->format->Rmask == 0x000000ff)
							texture_format = GL_RGB;
					else
							texture_format = GL_BGR;
			} 
			else 
			{
				// not true color
			}

			// set texture coords
			SDL_Coords.w = Surface_Temp->w;
			SDL_Coords.h = Surface_Temp->h;

			glGenTextures(1, &m_Texture);

			// Bind the texture object
			glBindTexture(GL_TEXTURE_2D, m_Texture);
 
			// Set the texture's stretching properties
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
			// Edit the texture object's image data using the information SDL_Surface gives us
			glTexImage2D(GL_TEXTURE_2D, 0, num_colors, Surface_Temp->w, Surface_Temp->h, 0,
				texture_format, GL_UNSIGNED_BYTE, Surface_Temp->pixels);

			/*
			if(m_TextureType == TEXTURE_TILE)
			{
				ExtractTile(Surface_Temp);
			}
			else
			{
				// set alpha for png-like formats
				m_Texture.reset(SDL_DisplayFormatAlpha(Surface_Temp));
			}*/

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

	GLuint CTexture::GetTexture()
	{
		LoadSurfaceMemory();

		return m_Texture;
	}

	void CTexture::ExtractTile(SDL_Surface* sfc_origin)
	{
	/*	U32 rmask, gmask, bmask, amask;

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
		m_Texture.reset(SDL_CreateRGBSurface(SDL_HWSURFACE, Tile_Coords.w, Tile_Coords.h,
									sfc_origin->format->BitsPerPixel,
									0x00ff0000,
									0x0000ff00,
									0x000000ff,
									(sfc_origin->format->BitsPerPixel == 32 ? 0xff000000 : 0)));

		SDL_SetAlpha(sfc_origin, 0, SDL_ALPHA_OPAQUE);

		if(m_Texture == NULL)
		{
			TRACE("Creating surface tile failed: %s", SDL_GetError());
		}
		else
		{
			TRACE("Blitting surface to tile, %d - %d, %d, %d", Tile_Coords.x, Tile_Coords.y, Tile_Coords.w, Tile_Coords.h);
			// blit surface tile to the new created surface
			//SDL_BlitSurface(sfc_origin, &Tile_Coords, m_Texture.get(), NULL);
		}

	}*/
	}
}

