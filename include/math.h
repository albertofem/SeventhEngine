/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.0625
 *
 */

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

		S32 pos_x;
		S32 pos_y;
	};
}
