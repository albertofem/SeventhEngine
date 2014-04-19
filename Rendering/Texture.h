/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
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
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/GL.h>
#include <GL/GLU.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

#include "RenderingResource.h"
#include "ResourceManager/ResourceTexture.h"
#include "Vector2.h"

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

namespace Seventh
{
	class Texture : public RenderingResource
	{
	public:
		Texture(std::string packName, std::string textureName);
		Texture(std::string filename);
		~Texture();

		bool load();
		void unload();
		void render();

		GLuint getTextureData();

	private:
		bool mLoaded;
		std::string mFilename;
		GLuint mTexture;
		ResourceTexture* mResource;
	};
}

#endif