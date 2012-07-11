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

#include "resources.h"

#include "Rendering/CTile.h"

namespace Seventh
{
	CTile::CTile(std::string filename, s_Tile* tile)
	{
		m_FromX = tile->posx;
		m_FromY = tile->posy;

		m_CurrentX = 0;
		m_CurrentY = 0;

		m_Width = tile->width;
		m_Height = tile->height;

		// create new GLtexture
		m_GLtexture.reset(new GLtexture);

		// load texture resource
		m_GLtexture->load(filename, TEXTURE_TILE, m_FromX, m_FromY, m_Width, m_Height);

		m_FirstDraw = true;
		m_Draw = true;
	}

	CTile::CTile(boost::shared_ptr< GLtexture >& texture)
	{
		m_GLtexture = texture;
	}

	CTile::~CTile()
	{

	}

	CTile::CTile(const CTile& rhs)
	{

	}
}
