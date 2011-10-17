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
 * @since		2011.1015
 *
 */

#include "common.h"

#include "EventsCore/CEventsCore.h"

namespace Seventh
{
	CEventsCore::CEventsCore()
	{
		// do nothing
	}

	CEventsCore::~CEventsCore()
	{
		// do nothing
	}

	void CEventsCore::Start()
	{

	}

	void CEventsCore::RegisterEvent(SDL_Event &event_type)
	{
		e_EventCases c_case;

		switch(event_type.type)
		{
		case SDL_KEYDOWN:
			Handle_KeyDown(event_type.key);
			break;
		}

		// push back this event
		m_Events.push_back(c_case);

		TRACE("Registered event");
	}

	void CEventsCore::RemoveEvents()
	{
		m_Events.clear();
	}

	e_EventCases CEventsCore::Handle_KeyDown(SDL_KeyboardEvent ekey)
	{
		switch(ekey.keysym.sym)
		{
		case SDLK_UP:
			return KEY_PRESS_UP;
			break;

		case SDLK_DOWN:
			return KEY_PRESS_DOWN;
			break;

		case SDLK_LEFT:
			return KEY_PRESS_LEFT;
			break;

		case SDLK_RIGHT:
			return KEY_PRESS_RIGHT;
			break;
		}
	}

	void CEventsCore::Shutdown()
	{
		// clear events vector
		m_Events.clear();
	}
}
