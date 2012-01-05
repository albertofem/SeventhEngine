/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
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

#include "SDL_image.h"

#include "Rendering/GLtexture.h"

namespace Seventh
{
	void GLtexture::draw(U32 x, U32 y)
	{
		TRACE("Drawing texture ID: %d in %dx%d", GLtexture_id, x, y);

		if(GLtexture_id == 0)
			throw seventh_displaycore_exception("Couldn't draw texture, it hans't been initialized", STH_EXCEPTION_GLTEXTURE_NOT_INITIALIZED);

		// GL stuff
		glBindTexture(GL_TEXTURE_2D, &GLtexture_id);

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
			glTexCoord2i(0, 0);
			glVertex3f(gl_x, gl_y, 0.0f);

			glTexCoord2i(1, 0);
			glVertex3f(gl_x+gl_w, gl_y, 0.f);

			glTexCoord2i(1, 1);
			glVertex3f(gl_x+gl_w, gl_y+gl_h, 0.f);

			glTexCoord2i(0, 1);
			glVertex3f(gl_x, gl_y+gl_h, 0.f);
		glEnd();
	}

	void GLtexture::load(std::string filename)
	{
		if(GLtexture_id == 0)
		{
			SDL_Surface* temp;
			temp = IMG_Load(filename.c_str());

			if(temp == NULL)
				throw seventh_displaycore_exception("Couldn't load surface resource", STH_EXCEPTION_SURFACE_LOAD);

			GLint GL_colors;
			GLenum GL_texture_format;

			/**
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

			/**
			 * set width & height
			 */
			GLwidth = temp->w;
			GLheight = temp->h;

			/**
			 * generate OpenGL texture
			 */
			glGenTextures(1, &GLtexture_id);
			glBindTexture(GL_TEXTURE_2D, &GLtexture_id);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_colors, GLwidth, GLheight, 0, GL_texture_format, GL_UNSIGNED_BYTE, temp->pixels);

			/**
			 * free temporary resource
			 */
			SDL_FreeSurface(temp);
		}
	}
}
