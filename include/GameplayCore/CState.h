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
 * @since		2011.0813
 *
 */

#include "common.h"
#include "events.h"

#ifndef STH_CSTATE_H_
#define STH_CSTATE_H_

namespace Seventh
{
	class CEngine;

	class CState
	{

	public:
		CState();
		virtual ~CState();

		virtual void Update();

		virtual void OnEvent(EVENT_INFO event_case);

	private:
		std::string m_NextState;
	};
}

#endif
