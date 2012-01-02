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

#include "Engine/CEngine.h"

#ifndef STH_CLAYERMANAGER_H_
#define STH_CLAYERMANAGER_H_

namespace Seventh
{
	class CLayer;
	class CEntity;
	class CMap;
	class CEntityManager;

	class CLayerManager
	{
	public:
		CLayerManager();
		~CLayerManager();

		void Render();

		void RegisterOverallEntity(std::string name, CEntity* entity);

	private:
		// layers
		std::map< U16, boost::shared_ptr<CLayer> > m_Layers;

		// overall entities
		std::map< std::string, CEntity* > m_OverallEntities;

		// current map
		CMap* m_CurrentMap;

		// num of layers
		U16 m_Total;

		CEntityManager* m_EntityManager;

		U16 CreateLayer();
		boost::shared_ptr<CLayer> _Layer(U16 layer_id);

		void RenderOverallEntities();
	};
}

#endif
