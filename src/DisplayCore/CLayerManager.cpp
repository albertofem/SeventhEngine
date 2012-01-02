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
#include "Engine/CEngine.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CDisplayCore.h"
#include "DisplayCore/CLayer.h"
#include "EntityCore/CEntity.h"

namespace Seventh
{
	CLayerManager::CLayerManager()
		: m_Total(0), m_EntityManager(CEngine::_Entities())
	{
		// do nothing
	}

	CLayerManager::~CLayerManager()
	{
		// do nothing
	}

	void CLayerManager::Render()
	{
	}

	U16 CLayerManager::CreateLayer()
	{
		LAYER temp(new CLayer);

		U16 tempID = m_Total;

		m_Layers[m_Total] = temp;

		m_Total++;

		return tempID;
	}

	void CLayerManager::RegisterOverallEntity(std::string name, CEntity* entity)
	{
		m_OverallEntities[name] = entity;

		m_EntityManager->RegisterEntity(name, entity);

		entity->SetEntityLayer(-1);
	}

	void CLayerManager::RenderOverallEntities()
	{
	}

}
