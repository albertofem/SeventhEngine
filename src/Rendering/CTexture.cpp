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
	{
		// create new GLtexture
		m_GLtexture.reset(new GLtexture);

		// load texture resource
		m_GLtexture->load(filename);

		m_Draw = true;
	}

	CTexture::~CTexture()
	{
		TRACE("Calling texture destructor");
	}

	CTexture::CTexture(boost::shared_ptr< GLtexture >& texture)
	{
		m_GLtexture = texture;
	}

	boost::shared_ptr< GLtexture > CTexture::GetGLtexture()
	{
		return m_GLtexture;
	}

	void CTexture::Render(U64 pos_x, U64 pos_y)
	{
		if(m_Draw)
			m_GLtexture->draw(pos_x, pos_y);

		m_Draw = false;
	}

	void CTexture::Hide()
	{
		m_Draw = false;
		m_Hide = true;
	}
}
