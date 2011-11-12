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

#include "common.h"
#include "Engine/CEngine.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CTextureManager.h"
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
		RenderMapContainer(m_Layers);

		// render overall textures
		RenderOverallEntities();
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
		RenderMapContainer(m_OverallEntities);
	}

}
