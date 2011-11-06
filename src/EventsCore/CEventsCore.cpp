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
	CEventsCore::CEventsCore(CEngine* engine)
	{
		m_Engine = engine;

		// keyboard interval and delay
		SDL_EnableKeyRepeat(1, 1);
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
		EVENT_INFO c_case;

		switch(event_type.type)
		{
		case SDL_KEYDOWN:
			c_case = Handle_KeyDown(event_type.key);
			break;

		case SDL_QUIT:
			// shutdown engine by sending a signal
			m_Engine->EngineCall(STOP_ENGINE);
			break;

		default:
			c_case.ecase = KEY_UNKNOWN;
			break;

		}

		PropagateEvent(c_case);
	}

	EVENT_INFO CEventsCore::Handle_KeyDown(SDL_KeyboardEvent ekey)
	{
		EVENT_INFO event_ret;

		switch(ekey.keysym.sym)
		{
		case SDLK_UP:
			event_ret.ecase = KEY_PRESS_UP;
			break;

		case SDLK_DOWN:
			event_ret.ecase = KEY_PRESS_DOWN;
			break;

		case SDLK_LEFT:
			event_ret.ecase = KEY_PRESS_LEFT;
			break;

		case SDLK_RIGHT:
			event_ret.ecase = KEY_PRESS_RIGHT;
			break;

		case SDLK_a:
			event_ret.ecase = KEY_PRESS_A;
			break;

		case SDLK_s:
			event_ret.ecase = KEY_PRESS_S;
			break;

		case SDLK_w:
			event_ret.ecase = KEY_PRESS_W;
			break;

		case SDLK_d:
			event_ret.ecase = KEY_PRESS_D;
			break;
		}

		if(ekey.state == PRESSED)
			event_ret.estate = PRESSED;
		else
			event_ret.estate = RELEASED;

		return event_ret;
	}

	void CEventsCore::Shutdown()
	{
	}

	void CEventsCore::PropagateEvent(EVENT_INFO event_case)
	{
		// propage events across the engine
		// first one, states
		m_Engine->_Gameplay()->_States()->CheckEvents(event_case);
	}
}
