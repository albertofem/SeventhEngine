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
#include "events.h"

#ifndef STH_CSTATE_H_
#define STH_CSTATE_H_

namespace Seventh
{
	class CState
	{

	public:
		CState();
		virtual ~CState();

	public:
		/**
		 * Public class methods that should be
		 * overriden in the final entity inherited
		 * classes. Those will be called to provide
		 * actions to events, camera events, engine
		 * calls, etc.
		 */
		virtual void UpdateGameLogic() = 0;
		virtual void OnEvent(EVENT_INFO event_case) = 0;
		virtual void OnCameraChange() = 0;
		virtual void OnRegister() = 0;
		virtual void OnDelete() = 0;

	private:
		std::string m_NextState;
	};
}

#endif
