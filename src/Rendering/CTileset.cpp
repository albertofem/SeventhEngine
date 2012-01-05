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

#include "Rendering/CTileset.h"
#include "Rendering/CTile.h"

namespace Seventh
{
	CTileset::CTileset(std::string filename)
	{
		m_CounterTiles = 0;
	}

	CTileset::~CTileset()
	{
	}

	CTileset::CTileset(boost::shared_ptr< GLtexture >& texture)
	{
		m_GLtexture = texture;
	}

	boost::shared_ptr< GLtexture > CTileset::GetGLtexture()
	{
		return m_GLtexture;
	}

	U64 CTileset::LoadTile(s_Tile* tile)
	{
		// look for the tile if already loaded
		std::map< s_Tile*, U64 >::const_iterator it_tile;

		it_tile = m_LoadedTiles.find(tile);

		m_CounterTiles++;

		if(it_tile == m_LoadedTiles.end())
		{
			// found, return the same CTile if it has 0 references
			// or a copy if has more
			if(m_Tiles[it_tile->first].refcount == 0)
			{
				// return the same, NOT THREAD SAFE!!
				m_CounterTiles--;
				return it_tile->first;
			}
			else
			{
				// return a copy, calling the cpy ctor
				m_Tiles[m_CounterTiles].resource.reset(new CTile(*m_Tiles[it_tile->first].resource.get()));
			}
		}
		else
		{
			// create new tile
			m_Tiles[m_CounterTiles].resource.reset(new CTile(m_GLtexture, tile));
		}

		return m_CounterTiles;
	}
}
