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
#include "Engine/CClock.h"

namespace Seventh
{
	boost::shared_ptr<CClock> CClock::_instance;

	CClock::CClock()
		: m_TicksPerSecond(50),
		m_SkipTicks(1000/m_TicksPerSecond),
		m_MaxFrameskip(10),
		m_Loops(0)
	{
		// do nothing
	}

	boost::shared_ptr<CClock> CClock::getInstance()
	{
		if(_instance == 0)
		{
			// first call of CClock
			_instance.reset(new CClock);
		}

		return _instance;
	}

	bool CClock::logic()
	{
		if(SDL_GetTicks() > m_LastTick && m_Loops < m_MaxFrameskip)
			return true;
	}

	void CClock::reset()
	{
		m_Loops = 0;
	}

	void CClock::init()
	{
		m_LastTick = SDL_GetTicks();
	}

	void CClock::update()
	{
		m_LastTick += m_SkipTicks;
		m_Loops++;
	}
}
