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

#ifndef _WIN32
	#ifndef NDEBUG
		#define TRACE(arg, ...) printf(arg, ##__VA_ARGS__); std::cout << std::endl;
	#else
		#define TRACE(arg, ...)
#endif
#else
	#include <Platform/windows/trace.h>
#endif

#ifndef STH_COMMON_H_
#define STH_COMMON_H_

#ifdef _WIN32
	#include <windows.h>
#endif

#include <gl/GL.h>
#include <gl/GLU.h>

#ifdef _WIN32
	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "glu32.lib")
	#pragma comment(lib, "SDL.lib")
	#pragma comment(lib, "SDLmain.lib")
	#pragma comment(lib, "SDL_image.lib")
#endif

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
#include <SDL_opengl.h>

#include "sth_math.h"
#include "exception.h"

#include <cassert>

#include "functors.h"

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

	class CEventsCore;
	typedef boost::shared_ptr<CEventsCore> EVENTS_CORE;

	class CEntityManager;
	typedef boost::shared_ptr<CEntityManager> ENTITY_MANAGER;

	class CStateManager;
	typedef boost::shared_ptr<CStateManager> STATE_MANAGER;

	class CResourceManager;
	typedef boost::shared_ptr<CResourceManager> RESOURCE_MANAGER;

	class CState;
	typedef boost::shared_ptr<CState> STATE;

	class CLayer;
	typedef boost::shared_ptr<CLayer> LAYER;
}

/**
 * types of cameras
 */
namespace Seventh
{
	enum e_CameraType
	{
		CAMERA_STATIC = 0x0,
		CAMERA_ATTACHED
	};
}

#endif
