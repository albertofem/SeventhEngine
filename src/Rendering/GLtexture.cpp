/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2012 Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	0.1
 *
 */

#include "common.h"

#include <SDL/SDL_image.h>

#include "Rendering/GLtexture.h"

namespace Seventh
{
	void GLtexture::draw(U32 x, U32 y)
	{
		TRACE("Drawing texture ID: %d, tamaño: %dx%d", GLtexture_id, x, y, GLwidth, GLheight);

		if(GLtexture_id == 0)
			throw seventh_displaycore_exception("Couldn't draw texture, it hasn't been initialized", STH_EXCEPTION_GLTEXTURE_NOT_INITIALIZED);

		// GL stuff
		glBindTexture(GL_TEXTURE_2D, GLtexture_id);

		if(GLalpha)
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		GLint gl_x = x;
		GLint gl_y = y;
		GLint gl_w = GLwidth;
		GLint gl_h = GLheight;

		if(x<0)
		{
			gl_x = 0;
		}

		if(y<0)
		{
			gl_y = 0;
		}

		glBegin(GL_QUADS);
			glTexCoord2f(0, 0);
			glVertex3f(gl_x, gl_y, 0.0f);

			glTexCoord2f(1, 0);
			glVertex3f(gl_x+gl_w, gl_y, 0.f);

			glTexCoord2f(1, 1);
			glVertex3f(gl_x+gl_w, gl_y+gl_h, 0.f);

			glTexCoord2f(0, 1);
			glVertex3f(gl_x, gl_y+gl_h, 0.f);
		glEnd();
	}

	void GLtexture::load(std::string filename, e_TextureFormat format, U32 tile_fromx, U32 tile_fromy, U32 tile_width, U32 tile_height)
	{
		if(GLtexture_id == 0)
		{
			SDL_Surface* temp;
			temp = IMG_Load(filename.c_str());

			if(temp == NULL)
				throw seventh_displaycore_exception("Couldn't load surface resource", STH_EXCEPTION_SURFACE_LOAD);

			// in case we have a tile, extract it
			if(format == TEXTURE_TILE)
			{
				temp = ExtractTile(temp, tile_fromx, tile_fromy, tile_width, tile_height);
			}

			GLint GL_colors;
			GLenum GL_texture_format;

			/*
			 * Get the colors/channels
			 * from the surface data
			 */
			GL_colors = temp->format->BytesPerPixel;

			if(GL_colors == 4)
			{
				// alpha channel found
				GLalpha = true;

				if(temp->format->Rmask == 0x000000ff)
					GL_texture_format = GL_RGBA;
				else
					GL_texture_format = GL_BGRA;
			}
			else if(GL_colors == 3)
			{
				GLalpha = false;

				if(temp->format->Rmask == 0x000000ff)
					GL_texture_format = GL_RGB;
				else
					GL_texture_format = GL_BGR;
			}

			/*
			 * set width & height
			 */
			GLwidth = temp->w;
			GLheight = temp->h;

			/*
			 * generate OpenGL texture
			 */
			glGenTextures(1, &GLtexture_id);
			glBindTexture(GL_TEXTURE_2D, GLtexture_id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_colors, GLwidth, GLheight, 0, GL_texture_format, GL_UNSIGNED_BYTE, temp->pixels);

			/*
			 * free temporary resource
			 */
			SDL_FreeSurface(temp);
		}
	}

	SDL_Surface* GLtexture::ExtractTile(SDL_Surface* sfc_origin, U32 tile_fromx, U32 tile_fromy, U32 tile_width, U32 tile_height)
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

		SDL_Surface* surface_tile;

		// create a surface from scratch
		surface_tile = SDL_CreateRGBSurface(SDL_HWSURFACE, tile_width, tile_height,
									sfc_origin->format->BitsPerPixel,
									0x00ff0000,
									0x0000ff00,
									0x000000ff,
									(sfc_origin->format->BitsPerPixel == 32 ? 0xff000000 : 0));

		SDL_SetAlpha(sfc_origin, 0, SDL_ALPHA_OPAQUE);

		if(surface_tile == NULL)
		{
			TRACE("Creating surface tile failed: %s", SDL_GetError());
			return NULL;
		}
		else
		{
			SDL_Rect rect_temp;

			rect_temp.x = tile_fromx;
			rect_temp.y = tile_fromy;
			rect_temp.w = tile_width;
			rect_temp.h = tile_height;

			TRACE("Creating tile from: %dx%d, size: %dx%d", tile_fromx, tile_fromy, tile_width, tile_height);

			// blit surface tile to the new created surface
			if(SDL_BlitSurface(sfc_origin, &rect_temp, surface_tile, NULL) == -1)
			{
				TRACE("Blitting unsuccesfull!");
			}

			SDL_FreeSurface(sfc_origin);

			return surface_tile;
		}

	}
}
