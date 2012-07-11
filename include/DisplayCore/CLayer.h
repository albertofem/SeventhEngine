
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

#include <vector>

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
		
/*
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
