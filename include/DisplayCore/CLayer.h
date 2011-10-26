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
 * @since		2011.0816
 *
 */

#include <vector>

#include "DisplayCore/CMap.h"

#ifndef STH_CLAYER_H_
#define STH_CLAYER_H_

namespace Seventh
{
	class CLayer
	{
	public:
		CLayer();
		~CLayer();

		void UpdateGameLogic();
		void Render();

	private:
		/**
		 * The structure of a layer is simple
		 *
		 * Map: loaded from the map container
		 * Entities: user tells where to locate them
		 * OverallTextures: for effects and such (mist, etc.)
		 *
		 * It must be rendered in this order, to keep
		 * layer strata OK
		 *
		 */

		// contained map of contained entities
		std::map< std::string, U32 > m_Entities;

		// method to render textures, entities and the map
		void RenderEntities();
		void RenderMapLayer();
	};
}

#endif
