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

#ifndef STH_GLTEXTURE_H_
#define STH_GLTEXTURE_H_

namespace Seventh
{
	class GLtexture
	{
	public:
		GLtexture()
			: GLwidth(0), GLheight(0), GLtexture_id(0)
		{
		}

		~GLtexture()
		{
			glDeleteTextures(1, get());
		}

		GLuint& get()
		{
			return GLtexture_id;
		}

		void draw(U32 x, U32 y);
		void load(std::string filename);

	private:
		GLuint GLtexture_id;

		bool GLalpha;

		U32 GLwidth;
		U32 GLheight;
	};
}

#endif
