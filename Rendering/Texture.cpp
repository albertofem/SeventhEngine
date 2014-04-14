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

#include "Texture.h"
#include "ResourceManager/ResourceManager.h"

namespace Seventh
{
	Texture::Texture(std::string filename)
	{
		mFilename = filename;
	}

	Texture::Texture(std::string packName, std::string textureName)
	{
		mResource = (ResourceTexture*) GResourceManager.getResourceFromPack(packName, "textures", textureName);
	}

	Texture::~Texture()
	{
	}

	bool Texture::load()
	{
		if (mLoaded)
			return true;

		ILuint imageID;
		ILboolean success;
		ILenum error;

		ilGenImages(1, &imageID); 
		ilBindImage(imageID); 

		success = ilLoadImage(mFilename.c_str());

		if (success)
		{
			ILinfo ImageInfo;

			iluGetImageInfo(&ImageInfo);

			if (ImageInfo.Origin == IL_ORIGIN_UPPER_LEFT)
			{
				iluFlipImage();
			}

			success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);

			if (!success)
			{
				error = ilGetError();
				LOG_ERROR("Rendering: Image conversion failed: '%s'", iluErrorString(error));
			}

			glGenTextures(1, &mTexture);

			glBindTexture(GL_TEXTURE_2D, mTexture);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				ilGetInteger(IL_IMAGE_FORMAT),
				ilGetInteger(IL_IMAGE_WIDTH),
				ilGetInteger(IL_IMAGE_HEIGHT),
				0,
				ilGetInteger(IL_IMAGE_FORMAT),
				GL_UNSIGNED_BYTE,
				ilGetData()
			);
		}
		else 
		{
			error = ilGetError();
			LOG_ERROR("Rendering: Image loading failed: '%s'", iluErrorString(error));
		}

		ilDeleteImages(1, &imageID);

		mLoaded = true;
	}

	GLuint Texture::getTextureData()
	{
		return mTexture;
	}

	void Texture::unload()
	{
		mLoaded = false;
	}

	void Texture::render()
	{
		if (!mLoaded)
			load();

		glBindTexture(GL_TEXTURE_2D, mTexture);

		float hsize = 1.0f;
		float vsize = 1.0f;

		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-hsize, -vsize, 0.0f);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-hsize, vsize, 0.0f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(hsize, vsize, 0.0f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(hsize, -vsize, 0.0f);
		glEnd();
	}
}
