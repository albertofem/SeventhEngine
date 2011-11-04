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

#include "common.h"

#include "Engine/CClock.h"
#include "CEngineConfig.h"
#include "DisplayCore/CDisplayCore.h"
#include "GameplayCore/CGameplayCore.h"
#include "EventsCore/CEventsCore.h"
#include "ResourceManager/CResourceManager.h"

#define TIXML_USE_STL

#ifndef STH_CENGINE_H_
#define STH_CENGINE_H_

namespace Seventh
{
	/**
	 * Main engine class, take care of initialice
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
		/**
		 * subsytem core
		 */
		ENGINE_CONFIG EngineConfig;
		DISPLAY_CORE Display;
		GAMEPLAY_CORE Gameplay;
		static RESOURCE_MANAGER Resources;
		EVENTS_CORE Events;
		ENTITY_MANAGER Entities;

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
		inline void set__CONFIG_INI(std::string config_ini)
		{
			__CONFIG_INI = config_ini;
		}

		inline void set__RESOURCES_XML(std::string filename)
		{
			__RESOURCES_XML = filename;
		}

		// configuration getters methods
		inline std::string get__CONFIG_INI()
		{
			return CEngine::__CONFIG_INI;
		}

		inline std::string get__RESOURCES_XML()
		{
			return CEngine::__RESOURCES_XML;
		}

		inline GAMEPLAY_CORE _Gameplay()
		{
			return Gameplay;
		}

		inline DISPLAY_CORE _Display()
		{
			return Display;
		}

		inline RESOURCE_MANAGER _Resources()
		{
			return Resources;
		}

		inline ENTITY_MANAGER _Entities()
		{
			return Entities;
		}

	public:
		static void EngineCall(const ENGINE_SIGNAL signal);

	};
}

#endif
