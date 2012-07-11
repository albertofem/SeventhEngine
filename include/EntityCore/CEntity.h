
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

#include <string>

#include "common.h"

#include "resources.h"

#include "Engine/CEngine.h"

#ifndef STH_CENTITY_H_
#define STH_CENTITY_H_

namespace Seventh
{
	class CEntity
	{
		friend class CEntityManager;

	public:
		CEntity();
		CEntity(STH_Position& initial_position);
		virtual ~CEntity();

		
/*
		 * TODO: copy & assignement constructor
		 * also comparators (position) operators
		 */

	public:
		
/*
		 * Public class methods that should be
		 * overriden in the final entity inherited
		 * classes. Those will be called to provide
		 * actions to events, camera events, engine
		 * calls, etc.
		 */
		void UpdateGameLogic();
		virtual void OnEvent(EVENT_INFO event_case) = 0;
		virtual void OnCameraChange() = 0;
		virtual void OnRegister() = 0;
		virtual void OnDelete() = 0;

	public:
		void SetAnimation(std::string animation_name);
		void SetTexture(std::string animation_name);
		void SetTile(std::string tileset, std::string tile);
		void Clear();

	private:
		e_EntityAsset m_CurrentAsset;
		std::string m_CurrentResourceName;

		CEngine* m_Engine;
		
/*
		 * This method checks if the current camera
		 * is attached to this particular entity
		 */
		bool m_CameraAttached;

	public:
		void AttachCamera() { m_CameraAttached = true; };
		void DettachCamera() { m_CameraAttached = false; };

		STH_INLINE void SetEntityLayer(S16 layer)
		{
			m_EntityLayer = layer;
		}


	private:
		
/*
		 * Entity possition members and methods
		 */
		STH_Position m_Position;

		S16 m_EntityLayer;

		U64 m_ResourceID;

		bool m_Show;

	public:
		void Move(STH_Transform& transform);
		void MoveToPosition(STH_Position& new_position);

		void Stop();
		void Hide();
		void Show();
	};
}

#endif
