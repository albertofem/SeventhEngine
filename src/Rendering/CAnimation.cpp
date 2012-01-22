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

#include "resources.h"

#include "Engine/CEngine.h"
#include "DisplayCore/CDisplayCore.h"
#include "Rendering/CAnimation.h"

namespace Seventh
{
	CAnimation::CAnimation()
	{
	}

	CAnimation::~CAnimation()
	{
	}

	void CAnimation::Init(U16 frame_rate, e_AnimationType type)
	{
		m_CurrentFrame = 0;
		m_MaxFrames = 0;

		m_FrameIncrement = 1;
		m_FrameRate = frame_rate;

		m_Oscillation = false;
		m_OldTime = 0;
	}

	void CAnimation::SetFrames(U16 num_frames)
	{
		m_MaxFrames = num_frames;
	}

	/**
	 * Texture frames constructors
	 */
	CAnimation::CAnimation(std::vector< std::string >& texture_frames, U16 frame_rate)
	{
		// init texture properly
		Init(frame_rate, ANIM_TEXTURE);

		// extract textures and load them
		std::vector< std::string >::const_iterator frames;

		U16 i = 0;

		for(frames = texture_frames.begin(); frames != texture_frames.end(); frames++)
		{
			U64 resource_id = CEngine::_Resources()->LoadTexture(*frames);

			// insert this resource id in the internal map
			m_AnimationFrames[i] = resource_id;
			i++;
		}

		SetFrames(i);
	}

	CAnimation::CAnimation(std::vector< s_AnimationTile >& tile_frames, U16 frame_rate)
	{
		// init texture properly
		Init(frame_rate, ANIM_TILE);

		// extract textures and load them
		std::vector< s_AnimationTile >::const_iterator frames;

		U16 i = 0;

		for(frames = tile_frames.begin(); frames != tile_frames.end(); frames++)
		{
			U64 resource_id = CEngine::_Resources()->LoadTile((*frames).tileset, (*frames).tile);

			// insert this resource id in the internal map
			m_AnimationFrames[i] = resource_id;
			i++;
		}

		SetFrames(i);
	}


	bool CAnimation::UpdateFrames()
	{
		if(m_OldTime+m_FrameRate > SDL_GetTicks())
		{
			return false;
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

		return true;
	}

	void CAnimation::Render(U32 pos_x, U32 pos_y)
	{
		if(m_Type == ANIM_TEXTURE)
			CDisplayCore::_Render().RenderTexture(m_AnimationFrames[m_CurrentFrame], pos_x, pos_y);

		if(m_Type == ANIM_TILE)
			CDisplayCore::_Render().RenderTile(m_AnimationFrames[m_CurrentFrame], pos_x, pos_y);
	}
}
