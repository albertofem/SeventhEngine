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
 * @since		2011.1019
 *
 */

#ifndef STH_EVENTS_H_
#define STH_EVENTS_H_

namespace Seventh
{
	enum e_EventCases
	{
		KEY_UNKNOWN = 0x0,
		KEY_PRESS_UP,
		KEY_PRESS_DOWN,
		KEY_PRESS_LEFT,
		KEY_PRESS_RIGHT,

		KEY_PRESS_A,
		KEY_PRESS_S,
		KEY_PRESS_W,
		KEY_PRESS_D
	};

	enum e_EventState
	{
		STATE_UNKNOWN = 0x0,
		PRESSED,
		RELEASED
	};

	struct EVENT_INFO
	{
		e_EventCases ecase;
		e_EventState estate;
	};
}

#endif
