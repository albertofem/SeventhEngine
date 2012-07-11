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

#include "common.h"

#include "Engine/CClock.h"
#include "CEngineConfig.h"
#include "DisplayCore/CDisplayCore.h"
#include "GameplayCore/CGameplayCore.h"
#include "EventsCore/CEventsCore.h"
#include "ResourceManager/CResourceManager.h"
#include "EntityCore/CEntityManager.h"

#define TIXML_USE_STL

#ifndef STH_CENGINE_H_
#define STH_CENGINE_H_

namespace Seventh
{
	
/*
	 * Main engine class, take care of initialize
	 * every subsystem and loading the engine internal
	 * configuration: must be inherited by the game client
	 *
	 * @author Alberto
	 * @since 1.0
	 */
	class CEngine
	{
	public:
		void RunGame();

	protected:
		CEngine();
		~CEngine();

		virtual void setInitialConfig() = 0;

		void Initialize();

	private:
		void Shutdown();
		void UpdateGameLogic() throw();
		void RenderGame() throw();

	private:
		
/*
		 * subsytem core
		 */
		ENGINE_CONFIG EngineConfig;
		DISPLAY_CORE Display;
		GAMEPLAY_CORE Gameplay;
		static RESOURCE_MANAGER Resources;
		EVENTS_CORE Events;
		static ENTITY_MANAGER Entities;

		/*
		CSoundCore Sound;
		CInputCore Input;
		CEventsCore Events;
		CGameplayCore Gameplay;
		CEntityCore Entity;*/

	private:
		// configuration static vars
		static std::string __CONFIG_INI;
		static std::string __RESOURCES_XML;

		// static clock class
		static boost::shared_ptr<CClock> Clock;

		static bool s_Running;

	public:
		// configuration setters methods
		STH_INLINE void set__CONFIG_INI(std::string config_ini)
		{
			__CONFIG_INI = config_ini;
		}

		STH_INLINE void set__RESOURCES_XML(std::string filename)
		{
			__RESOURCES_XML = filename;
		}

		// configuration getters methods
		STH_INLINE std::string get__CONFIG_INI()
		{
			return CEngine::__CONFIG_INI;
		}

		STH_INLINE std::string get__RESOURCES_XML()
		{
			return CEngine::__RESOURCES_XML;
		}

		STH_INLINE GAMEPLAY_CORE _Gameplay()
		{
			return Gameplay;
		}

		STH_INLINE DISPLAY_CORE _Display()
		{
			return Display;
		}

		STH_INLINE static RESOURCE_MANAGER _Resources()
		{
			return Resources;
		}

		STH_INLINE static CEntityManager* _Entities()
		{
			return Entities.get();
		}

	public:
		static void EngineCall(const ENGINE_SIGNAL signal);

	};
}

#endif
