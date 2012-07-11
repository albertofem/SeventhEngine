
/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2012 Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	0.1
 *
 */

#include <iostream>
#include <map>

#include <string>

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


/*
 * engine configuration vars
 */
namespace STH_GLOBAL
{
	extern bool TEXTURE_PERSISTENT;
}

#ifdef _WIN32
	#include <windows.h>

	#include <gl/GL.h>
	#include <gl/GLU.h>

	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "glu32.lib")
	#pragma comment(lib, "SDL.lib")
	#pragma comment(lib, "SDLmain.lib")
	#pragma comment(lib, "SDL_image.lib")

	#define STH_INLINE		__forceinline
#else
#define STH_INLINE	inline
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
#include <SDL/SDL_opengl.h>

#include "sth_math.h"
#include "exception.h"

#include <cassert>

#include "functors.h"


/*
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


/*
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
