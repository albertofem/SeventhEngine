
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

#include "Rendering/CTexture.h"

#ifndef STH_CTILE_H_
#define STH_CTILE_H_

namespace Seventh
{
	class GLtexture;
	class CTile : public CTexture
	{
	public:
		CTile(std::string filename, s_Tile* tile);
		CTile(boost::shared_ptr < GLtexture > &texture);
		CTile(const CTile& rhs);
		~CTile();

	private:
		U64 m_FromX;
		U64 m_FromY;

		U64 m_Width;
		U64 m_Height;
	};
}

#endif
