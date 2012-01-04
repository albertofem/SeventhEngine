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

#include "Rendering/CRendering.h"

namespace Seventh
{
	CRendering::CRendering()
	{
		m_CounterTextures = 0;
	}

	CRendering::~CRendering()
	{
	}

	U64 CRendering::ResourceLoad_Texture(s_Texture* texture)
	{
		// check if already exists
		boost::shared_ptr< GLtexture > loaded;
		SRenderingResource< CTexture > new_texture;

		loaded = CheckResourceLoaded(texture->src);

		if(!loaded)
		{
			// create new texture
			new_texture.resource.reset(new CTexture(texture->src));

			// add it to already loaded textures
			m_TexturesLoaded[texture->src] = loaded;
		}
		else
		{
			// create new texture from previous GLtexture id
			new_texture.resource.reset(new CTexture(loaded));
		}

		new_texture.refcount++;

		// sum up the texture counter and add it to the map
		m_CounterTextures++;
		m_Textures[m_CounterTextures] = new_texture;

		return m_CounterTextures;
	}

	boost::shared_ptr< GLtexture > CRendering::CheckResourceLoaded(std::string filename)
	{
		std::map< std::string, boost::shared_ptr< GLtexture > >::const_iterator it;

		it = m_TexturesLoaded.find(filename);

		if(it == m_TexturesLoaded.end())
		{
			// doesn't exists
			return boost::shared_ptr< GLtexture >();
		}

		return it->second;
	}

	void CRendering::RenderTexture(U64 resource_id, U64 pos_x, U64 pos_y)
	{
		// first we have to check what textures are in the area
		// of this current texture position, and set the rest of textures
		// to redraw if the old position if the texture is going to redraw
		if(m_Textures[resource_id].resource->PositionChanged(pos_x, pos_y))
		{
			// look for collision in this area with the rest of texture
			// iterate map of textures and compare positions

			// also we need to check for collisions in the previous area
		}

		m_Textures[resource_id].resource->Render(pos_x, pos_y);
	}

	void CRendering::HideTexture(U64 resource_id)
	{
		m_Textures[resource_id].resource->Hide();
		m_Textures[resource_id].refcount--;

		if(m_Textures[resource_id].refcount == 0 && !STH_GLOBAL::TEXTURE_PERSISTENT)
		{
			// we can now delete texture safely
			m_Textures.erase(resource_id);
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool CRendering::CheckTextureCollision(CTexture* top_side, CTexture* down_side)
	{
		// first easy comparision
		if(top_side->GetCurrentX() > down_side->GetCurrentX()
			&& down_side->GetCurrentY())
	}
}
