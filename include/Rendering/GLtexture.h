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

#include "resources.h"

#ifndef STH_GLTEXTURE_H_
#define STH_GLTEXTURE_H_


namespace Seventh
{
	/**
	 * 
	 */
	class GLtexture
	{
	public:
		GLtexture()
			: GLwidth(0), GLheight(0), GLtexture_id(0)
		{
		}

		~GLtexture()
		{
			//TRACE("Deleting texture ID: %d\n-----------------", GLtexture_id);
			glDeleteTextures(1, &GLtexture_id);
		}

		GLuint& get()
		{
			return GLtexture_id;
		}

		void draw(U32 x, U32 y);

		void load(std::string filename, e_TextureFormat = TEXTURE_NORMAL,
				U32 tile_fromx = 0, U32 tile_fromy = 0,
				U32 tile_width = 0, U32 tile_height = 0);

		U32 get_w() { return GLwidth; };
		U32 get_h() { return GLheight; };

	private:
		GLuint GLtexture_id;

		bool GLalpha;

		U32 GLwidth;
		U32 GLheight;

		SDL_Surface* ExtractTile(SDL_Surface* sfc_origin,
			U32 tile_fromx, U32 tile_fromy, U32 tile_width, U32 tile_height);
	};
}

#endif
