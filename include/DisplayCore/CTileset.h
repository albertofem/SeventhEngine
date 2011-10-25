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
 * @since		2011.1025
 *
 */

#include <map>

#ifndef STH_TILESET_H_
#define STH_TILESET_H_

namespace Seventh
{
	class CTileset
	{
		friend class CMap;

	public:
		CTileset();
		~CTileset();

	private:
		std::map< U64, SDL_Rect > m_Tile;
	};
}

#endif
