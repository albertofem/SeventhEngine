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

#ifndef STH_CTEXTURE_H_
#define STH_CTEXTURE_H_

namespace Seventh
{
 	class CTexture
 	{
 	public:
		CTexture() { };
		CTexture(std::string filename);
		CTexture(boost::shared_ptr< GLtexture >& texture);

		~CTexture();

		boost::shared_ptr< GLtexture >& GetGLtexture()
		{
			return m_GLtexture;
		}

		void Render(U64 pos_x, U64 pos_y);
		void Hide();

		STH_INLINE bool PositionChanged(U64 posx, U64 pos_y);
		STH_INLINE U64 GetCurrentX();
		STH_INLINE U64 GetCurrentY();

		STH_INLINE U64 GetW();
		STH_INLINE U64 GetH();

		STH_INLINE void ReDraw() { m_Draw = true; };

	protected:
		boost::shared_ptr< GLtexture > m_GLtexture;

		bool m_Hide;
		bool m_Draw;
		bool m_FirstDraw;

		U64 m_CurrentX;
		U64 m_CurrentY;
	};
}

#endif
