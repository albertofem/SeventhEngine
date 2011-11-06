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

#include "Engine/CEngine.h"

#ifndef STH_CENTITY_H_
#define STH_CENTITY_H_

namespace Seventh
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

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
		void SetAnimation(std::string animation_name);
		void SetTexture(std::string animation_name);

		U8 m_CurrentRenderingResource;

		CEngine* m_Engine;

		void Render();

	};
}

#endif
