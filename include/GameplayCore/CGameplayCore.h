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
#include "GameplayCore/CStateManager.h"

#ifndef STH_CGAMEPLAYCORE_H_
#define STH_CGAMEPLAYCORE_H_

namespace Seventh
{
	class CGameplayCore
	{
	public:
		CGameplayCore();
		~CGameplayCore();

		void Start();
		void Shutdown();

		inline const STATE_MANAGER _StateManager() const
		{
			return m_StateManager;
		}

	private:
		STATE_MANAGER m_StateManager;

	// friend engine class
	friend class CEngine;
	};

}

#endif
