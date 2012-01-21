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

#ifndef STH_CANIMATION_H_
#define STH_CANIMATION_H_

namespace Seventh
{
	class CAnimation
	{
	public:
		CAnimation();
		~CAnimation();

		Render();

	private:
		std::vector< U64 > m_AnimationFrames;

		/**
		 * Members that directly controls
		 * the animation behavior
		 */
		U8 m_CurrentFrame;
		U8 m_FrameIncrement;
		U8 m_FrameRate;
		U8 m_MaxFrames;
		U64 m_OldTime;

		bool m_Oscillation;

		void UpdateFrames();
	}
}

#endif
