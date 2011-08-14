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

#ifndef STH_CCLOCK_H_
#define STH_CCLOCK_H_

namespace Seventh
{
	class CClock
	{
	public:
		static boost::shared_ptr<CClock> getInstance();

		void init();
		void update();

		bool game_update();
		void reset_loop();

	protected:
		CClock();
		CClock(const CClock& );
		CClock& operator=(const CClock& );

	private:
		static boost::shared_ptr<CClock> _instance;

		U32 m_LastTick;

		U8 m_TicksPerSecond;
		U8 m_SkipTicks;
		U8 m_MaxFrameskip;
		U32 m_Loops;
	};
}

#endif
