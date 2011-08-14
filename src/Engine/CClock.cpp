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
 * @since		2011.0814
 *
 */

#include "common.h"
#include "Engine/CClock.h"

namespace Seventh
{
	boost::shared_ptr<CClock> CClock::_instance;

	CClock::CClock()
		: m_TicksPerSecond(50),
		m_SkipTicks(1000/m_TicksPerSecond),
		m_MaxFrameskip(10),
		m_Loops(0)
	{
		// do nothing
	}

	boost::shared_ptr<CClock> CClock::getInstance()
	{
		if(_instance == 0)
		{
			// first call of CClock
			_instance.reset(new CClock);
		}

		return _instance;
	}

	bool CClock::game_update()
	{
		if(SDL_GetTicks() > m_LastTick && m_Loops < m_MaxFrameskip)
			return true;
	}

	void CClock::reset_loop()
	{
		m_Loops = 0;
	}

	void CClock::init()
	{
		m_LastTick = SDL_GetTicks();
	}

	void CClock::update()
	{
		m_LastTick += m_SkipTicks;
		m_Loops++;
	}
}
