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
 * @since		2011.1104
 *
 */

#include <map>
#include <string>

#include "common.h"

#ifndef STH_CENTITYMANAGER_H_
#define STH_CENTITYMANAGER_H_

namespace Seventh
{
	class CEntity;
	class CEntityManager
	{
		friend class CEventsCore;
		friend class CLayerManager;

	public:
		CEntityManager();
		~CEntityManager();

		CEntity* Entity(std::string name);

		void Start();

	private:
		void RegisterEntity(std::string name, CEntity* entity_ptr);

		std::map< std::string, CEntity* > m_Entities;

		void CheckEvents(EVENT_INFO event);
	};

}

#endif
