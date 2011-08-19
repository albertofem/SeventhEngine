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

#ifndef STH_TEXTURECOORD_H_
#define STH_TEXTURECOORD_H_

namespace Seventh
{
	struct TextureCoord
	{
		TextureCoord()
			: width(0), height(0), fromX(0), fromY(-1), toX(-1), toY(-1)
		{
		}

		TextureCoord(S32 fromX = -1, S32 fromY = -1, S32 toX = -1, S32 toY = -1)
		{
		}

		TextureCoord(const TextureCoord& rhs)
		{
			width = rhs.width;
			height = rhs.height;

			fromX = rhs.fromX;
			fromY = rhs.fromY;

			toX = rhs.toX;
			toY = rhs.toY;
		}

		U32 width;
		U32 height;

		S32 fromX;
		S32 fromY;

		S32 toX;
		S32 toY;
	};
}

#endif
