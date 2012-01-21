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

#include "Rendering/GLtexture.h"
#include "Rendering/CTexture.h"

namespace Seventh
{
	CTexture::CTexture(std::string filename)
		: m_CurrentX(0), m_CurrentY(0)
	{
		// create new GLtexture
		m_GLtexture.reset(new GLtexture);

		// load texture resource
		m_GLtexture->load(filename);

		m_FirstDraw = true;
		m_Draw = true;
	}

	CTexture::~CTexture()
	{
	}

	CTexture::CTexture(boost::shared_ptr< GLtexture >& texture)
	{
		m_GLtexture = texture;
	}

	bool CTexture::PositionChanged(U64 pos_x, U64 pos_y)
	{
		if(m_CurrentX == pos_x && m_CurrentY == pos_y)
		{
			return false;
		}

		return true;
	}

	void CTexture::Render(U64 pos_x, U64 pos_y)
	{
		if(!PositionChanged(pos_x, pos_y) && !m_Draw && !m_FirstDraw)
			return;

		m_CurrentX = pos_x;
		m_CurrentY = pos_y;

		m_GLtexture->draw(pos_x, pos_y);

		if(m_FirstDraw)
			m_FirstDraw = false;

		m_Draw = false;
	}

	void CTexture::Hide()
	{
		m_Draw = false;
		m_Hide = true;
	}

	U64 CTexture::GetCurrentX()
	{
		return m_CurrentX;
	}

	U64 CTexture::GetCurrentY()
	{
		return m_CurrentY;
	}

	U64 CTexture::GetW()
	{
		return m_GLtexture->get_w();
	}

	U64 CTexture::GetH()
	{
		return m_GLtexture->get_h();
	}
}
