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
#include "GameplayCore/CGameplayCore.h"

namespace Seventh
{

	CGameplayCore::CGameplayCore()
	{
		TRACE("Calling gameplay constructor");
	}

	void CGameplayCore::Start()
	{
		m_StateManager.reset(new CStateManager);
	}

	CGameplayCore::~CGameplayCore()
	{
	}
}
