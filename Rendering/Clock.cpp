/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
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
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include <Vendor/glfw/glfw3.h>
#include <time.h>

#include "Clock.h"

namespace Seventh
{
	template<> Clock* Singleton<Clock>::mInstance = 0;

	Clock::Clock()
		: mTicksPerSecond(50),
		mSkipTics(1000/mTicksPerSecond),
		mMaxFrameSkip(10),
		mLoops(0)
	{
		mLastTick = tick();
	}

	Clock::~Clock()
	{
	}

	bool Clock::step()
	{
		if(tick() > mLastTick && mLoops < mMaxFrameSkip)
			return true;

		return false;
	}

	void Clock::reset()
	{
		mLoops = 0;
	}

	void Clock::update()
	{
		mLastTick += mSkipTics;
		mLoops++;
	}

	clock_t Clock::tick()
	{
		return clock();
	}
}