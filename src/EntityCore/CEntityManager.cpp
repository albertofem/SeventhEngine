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

#include "EntityCore/CEntity.h"
#include "EntityCore/CEntityManager.h"

namespace Seventh
{
	CEntityManager::CEntityManager()
	{
	}

	CEntityManager::~CEntityManager()
	{
	}

	void CEntityManager::Start()
	{
		m_Entities.clear();
	}

	void CEntityManager::RegisterEntity(std::string name, CEntity* entity_ptr)
	{
		// add entity to the entity map
		m_Entities[name] = entity_ptr;

		// call entity onregister method
		m_Entities[name]->OnRegister();
	}

	CEntity* CEntityManager::Entity(std::string name)
	{
		return m_Entities[name];
	}

	void CEntityManager::CheckEvents(EVENT_INFO event)
	{
		// propage event across all entities
		OnEventGeneric(m_Entities, event);
	}

	void CEntityManager::UpdateGameLogic()
	{
		UpdateGameLogicGeneric(m_Entities);
	}
}
