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

#include "GameplayCore/CStateManager.h"

namespace Seventh
{
	CStateManager::CStateManager()
	{
	}

	void CStateManager::RegisterState(std::string name, CState& state)
	{
		// create temporary pointer
		STATE temp(new CState(state));

		// transfer pointer ownership to
		m_States[name] = temp;

		// pointer goes out of scope, ownership
		// already transfered
	}

	STATE CStateManager::getStatePtr(std::string name)
	{
		return m_States[name];
	}

	CStateManager::~CStateManager()
	{
		// clear states map
		m_States.clear();
	}
}
