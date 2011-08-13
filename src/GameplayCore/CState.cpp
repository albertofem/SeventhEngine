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
#include "GameplayCore/CState.h"

namespace Seventh
{
	CState::CState()
	{
	}

	void CState::setNextState(std::string state)
	{
		if(state == "")
			exit(0);

		m_NextState = state;
	}

	void CState::setNextState()
	{
		exit(0);
	}

	CState::~CState()
	{
	}

	void CState::OnUpdate()
	{
		TRACE("Oh my god!");
	}
}
