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
