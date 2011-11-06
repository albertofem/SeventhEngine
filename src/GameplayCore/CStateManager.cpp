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
 * @since		2011.0813
 *
 */

#include "EventsCore/CEventsCore.h"
#include "GameplayCore/CStateManager.h"

namespace Seventh
{
	CStateManager::CStateManager()
	{
	}

	void CStateManager::RegisterState(std::string name, CState* state)
	{
		// transfer pointer ownership to
		m_States[name] = state;

		// pointer goes out of scope, ownership
		// already transfered
	}

	CState* CStateManager::GetStatePtr(std::string name)
	{
		return m_States[name];
	}

	CStateManager::~CStateManager()
	{
		// clear states map
		m_States.clear();
	}

	void CStateManager::CheckEvents(EVENT_INFO event)
	{
		if(m_States.empty())
			return;

		// iterate map of overall textures
		std::map< std::string, CState* >::const_iterator it;

		for(it=m_States.begin(); it!=m_States.end(); it++)
		{
			GetStatePtr(it->first)->OnEvent(event);
		}
	}
}
