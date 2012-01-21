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

#include "main.h"
#include "Rendering/CAnimation.h"

namespace Seventh
{
	CAnimation::CAnimation()
	{
		m_CurrentFrame = 0;
		m_MaxFrames = 0;

		m_FrameIncrement = 0;
		m_FrameRate = 100;

		m_Oscillation = false;
		m_OldTime = 0;
	}

	void CAnimation::UpdateFrames()
	{
		if(m_OldTime+m_FrameRate > SDL_GetTicks())
		{
			return;
		}

		m_OldTime = SDL_GetTicks();

		m_CurrentFrame += m_FrameIncrement;

		if(m_Oscillation)
		{
			if(m_FrameIncrement > 0)
			{
				if(m_CurrentFrame >= m_MaxFrames)
				{
					m_FrameIncrement = -m_FrameIncrement;
				}
			}
			else
			{
				if(m_CurrentFrame <= 0)
				{
					m_FrameIncrement = -m_FrameIncrement;
				}
			}
		}
		else
		{
			if(m_CurrentFrame >= m_MaxFrames)
			{
				m_CurrentFrame = 0;
			}
		}
	}

	void CAnimation::Render(U32 pos_x, U32 pos_y)
	{
		UpdateFrames();
	}
}
