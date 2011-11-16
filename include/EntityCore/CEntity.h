/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.1015
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

		/**
		 * TODO: copy & assignement constructor
		 * also comparators (position) operators
		 */

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

	public:
		void SetAnimation(std::string animation_name);
		void SetTexture(std::string animation_name);
		void SetTile(std::string tileset, std::string tile);

		void Render();

	private:
		e_EntityAsset m_CurrentAsset;
		std::string m_CurrentResourceName;

		CEngine* m_Engine;
		/**
		 * This method checks if the current camera
		 * is attached to this particular entity
		 */
		bool m_CameraAttached;

	public:
		void AttachCamera() { m_CameraAttached = true; };
		void DettachCamera() { m_CameraAttached = false; };

		inline SetEntityLayer(S16 layer)
		{
			m_EntityLayer = layer;
		}


	private:
		/**
		 * Entity possition members and methods
		 */
		STH_Position m_Position;

		S16 m_EntityLayer;

		S64 m_ResourceID;

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
