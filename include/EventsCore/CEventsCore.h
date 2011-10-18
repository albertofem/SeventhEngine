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
		e_EventCases Handle_KeyDown(SDL_KeyboardEvent ekey);

	public:
		void RemoveEvents();

	private:
		std::vector< e_EventCases > m_Events;

		void PropagateEvent(e_EventCases event_case);

		CEngine* m_Engine;
	};
}

#endif
