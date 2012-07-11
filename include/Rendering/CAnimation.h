
/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2012 Alberto Fernández
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

#include "resources.h"

#ifndef STH_CANIMATION_H_
#define STH_CANIMATION_H_

namespace Seventh
{
	class CAnimation
	{
	public:
		CAnimation();
		~CAnimation();

		// texture constructor
		CAnimation(std::vector< std::string >& texture_frames, U16 frame_rate);

		// tile constructor
		CAnimation(std::vector< s_AnimationTile >& tile_frames, U16 frame_rate);

		void Render(U32 pos_x, U32 pos_y);

		bool PositionChanged(U32 pos_x, U32 pos_y) { return true; }
		void ReDraw() { return; }

		bool UpdateFrames();

	private:
		
/*
		 * Animation frames
		 *
		 * This map contains in the left the number
		 * of frame, in the right the ID of texture
		 * to show in that frame
		 */
		std::map< U16, U64 > m_AnimationFrames;

		
/*
		 * Members that directly controls
		 * the animation behavior
		 */
		U8 m_CurrentFrame;
		U8 m_FrameIncrement;
		U8 m_FrameRate;
		U8 m_MaxFrames;
		U64 m_OldTime;

		e_AnimationType m_Type;

		bool m_Oscillation;

		void Init(U16 frame_rate, e_AnimationType type);
		void SetFrames(U16 num_frames);

	};
}

#endif
