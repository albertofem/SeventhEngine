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
 * @since		2011.0625
 *
 */

#include <iostream>
#include <map>

#ifndef NDEBUG
	#define TRACE(arg, ...) printf(arg, ##__VA_ARGS__); std::cout << std::endl;
#else
	#define TRACE(arg, ...)
#endif

#ifndef STH_COMMON_H_
#define STH_COMMON_H_

namespace Seventh
{
	typedef enum
	{
		STH_TRUE = 1,
		STH_FALSE
	} STH_BOOL;

	typedef enum
	{
		STOP_ENGINE = 0
	} ENGINE_SIGNAL;
}

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#include <SDL/SDL.h>

#include "math.h"
#include "exception.h"

#include <cassert>

/**
 * define useful typedefs
 * to be used all around the
 * engine
 */
namespace Seventh
{
	class CEngineConfig;
	typedef boost::shared_ptr<CEngineConfig> ENGINE_CONFIG;

	class CDisplayCore;
	typedef boost::shared_ptr<CDisplayCore> DISPLAY_CORE;

	class CGameplayCore;
	typedef boost::shared_ptr<CGameplayCore> GAMEPLAY_CORE;

	class CStateManager;
	typedef boost::shared_ptr<CStateManager> STATE_MANAGER;

	class CState;
	typedef boost::shared_ptr<CState> STATE;
}

#endif
