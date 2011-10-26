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
		static ASSET_MANAGER Assets;
		EVENTS_CORE Events;

		/*
		CSoundCore Sound;
		CInputCore Input;
		CEventsCore Events;
		CGameplayCore Gameplay;
		CEntityCore Entity;*/

	private:
		// configuration static vars
		static std::string __CONFIG_INI;
		static boost::shared_ptr<CClock> Clock;

		static bool s_Running;

	public:
		// configuration setters methods
		inline void set__CONFIG_INI(std::string config_ini)
		{
			__CONFIG_INI = config_ini;
		}

		// configuration getters methods
		inline std::string get__CONFIG_INI()
		{
			return CEngine::__CONFIG_INI;
		}

		inline GAMEPLAY_CORE _Gameplay()
		{
			return Gameplay;
		}

		inline DISPLAY_CORE _Display()
		{
			return Display;
		}

		inline ASSET_MANAGER Resources()
		{
			return Assets;
		}

	public:
		static void EngineCall(const ENGINE_SIGNAL signal);

	};
}

#endif
