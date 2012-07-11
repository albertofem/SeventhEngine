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
