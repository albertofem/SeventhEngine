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
		m_CounterTilesets = 0;
		m_CounterTiles = 0;
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

	U64 CRendering::ResourceLoad_Tileset(s_Tileset* tileset)
	{
		// check if already exists
		boost::shared_ptr< GLtexture > loaded;
		SRenderingResource< CTileset > new_tileset;

		loaded = CheckResourceLoaded(tileset->src);

		if(!loaded)
		{
			// create new texture
			new_tileset.resource.reset(new CTileset(tileset->src));

			// add it to already loaded textures
			m_TexturesLoaded[tileset->src] = loaded;
		}
		else
		{
			// create new texture from previous GLtexture id
			new_tileset.resource.reset(new CTileset(loaded));
		}

		new_tileset.refcount++;

		// sum up the texture counter and add it to the map
		m_CounterTilesets++;
		m_Tilesets[m_CounterTilesets] = new_tileset;

		return m_CounterTilesets;
	}

	U64 CRendering::ResourceLoad_Tile(s_Tileset* tileset, s_Tile* tile)
	{
		// first, we have to load the tileset and get the ID
		U64 tileset_id = ResourceLoad_Tileset(tileset);

		if(tileset_id != 0)
		{
			m_Tilesets[tileset_id].resource->LoadTile(tile);
		}
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
			std::map< U64, SRenderingResource< CTexture > >::const_iterator it_collision;

			for(it_collision=m_Textures.begin(); it_collision!=m_Textures.end(); it_collision++)
			{
				m_Textures[it_collision->first].resource->ReDraw();
			}

			ClearScreen();
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
	}

	bool CRendering::CheckTextureCollision(CTexture* top_side, CTexture* down_side)
	{
		return true;
	}

	void CRendering::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
