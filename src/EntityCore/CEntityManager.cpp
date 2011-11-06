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
 * @since		2011.1106
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

	void CEntityManager::RegisterEntity(std::string name, CEntity* entity_ptr)
	{
		// add entity to the entity map
		m_Entities[name] = entity_ptr;

		// call entity onregister method
		m_Entities[name]->OnRegister();
	}
}
