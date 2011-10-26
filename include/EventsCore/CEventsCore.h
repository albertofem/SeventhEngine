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

#include <vector>

#ifndef STH_CEVENTSCORE_H_
#define STH_CEVENTSCORE_H_

#include "Engine/CEngine.h"

namespace Seventh
{
	class CEventsCore
	{
	public:
		CEventsCore(CEngine* engine);
		~CEventsCore();

		void RegisterEvent(SDL_Event &event_type);

		void Start();
		void Shutdown();

	private:
		EVENT_INFO Handle_KeyDown(SDL_KeyboardEvent ekey);

		void PropagateEvent(EVENT_INFO event_case);

		CEngine* m_Engine;
	};
}

#endif
