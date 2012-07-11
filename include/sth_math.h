
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

#ifdef _WIN32
	#include <stdint.h>
#endif

namespace Seventh
{
	typedef int8_t		S8;
	typedef uint8_t	U8;

	typedef int16_t	S16;
	typedef uint16_t	U16;

	typedef int32_t	S32;
	typedef uint32_t	U32;

	typedef int64_t	S64;
	typedef uint64_t	U64;

	struct STH_Transform
	{
		STH_Transform(S32 x, S32 y)
			: move_x(x), move_y(y)
		{
		}

		S32 move_x;
		S32 move_y;
	};

	struct STH_Position
	{
		STH_Position(S32 x, S32 y)
			: pos_x(x), pos_y(y)
		{

		}

		STH_Position()
		{
			pos_x = 0;
			pos_y = 0;
		}

		bool operator<(const STH_Position& rhs)
		{
			return (pos_x < rhs.pos_y && pos_y < rhs.pos_y);
		}

		S32 pos_x;
		S32 pos_y;
	};
}
