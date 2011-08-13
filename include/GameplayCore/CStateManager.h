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

// need complete declaration of CState
#include "common.h"
#include "GameplayCore/CState.h"

#ifndef STH_CSTATEMANAGER_H_
#define STH_CSTATEMANAGER_H_

namespace Seventh
{
	class CStateManager
	{
	public:
		CStateManager();
		~CStateManager();

		void registerState(std::string name, CState& state);
		STATE getStatePtr(std::string name);

	private:
		std::map< std::string, STATE > m_States;
	};
}

#endif
