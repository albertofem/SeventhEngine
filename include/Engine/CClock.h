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

#ifndef STH_CCLOCK_H_
#define STH_CCLOCK_H_

namespace Seventh
{
	class CClock
	{
	public:
		static boost::shared_ptr<CClock> getInstance();

		void init();
		void update();

		bool logic();
		void reset();

	protected:
		CClock();
		CClock(const CClock& );
		CClock& operator=(const CClock& );

	private:
		static boost::shared_ptr<CClock> _instance;

		U32 m_LastTick;

		U8 m_TicksPerSecond;
		U8 m_SkipTicks;
		U8 m_MaxFrameskip;
		U32 m_Loops;
	};
}

#endif
