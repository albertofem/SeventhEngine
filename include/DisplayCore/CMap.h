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
#include <vector>

#include "DisplayCore/CTile.h"

#ifndef STH_CMAP_H_
#define STH_CMAP_H_

namespace Seventh
{

	class CMap
	{
		friend class CTileset;

	public:
		CMap();
		~CMap();

		void Render(U16 layer_id);

	private:
		std::map< U32, CTileset > m_Tilesets;

		// collisions
		SDL_Surface* m_MapRender;
	};

}

#endif
