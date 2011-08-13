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
#include "Engine/CEngine.h"

namespace Seventh
{
	// initialize static configuration vars
	std::string CEngine::__CONFIG_INI = "";

	CEngine::CEngine()
	{
		// empty constructor, user must call the "Initialize()"
		// method in order to start the engine
	}

	CEngine::~CEngine()
	{
		Shutdown();
	}

	void CEngine::Initialize()
	{
		EngineConfig.reset(new CEngineConfig);

		/**
		 * start and get config
		 */
		EngineConfig->setConfigFile(CEngine::get__CONFIG_INI());
		EngineConfig->Start();

		/**
		 * start display core
		 */
		Display.reset(new CDisplayCore(EngineConfig));
		Display->Start();

		/**
		 * start gameplay core
		 */
		Gameplay.reset(new CGameplayCore);
		Gameplay->Start();

	}

	// main loop, everything happens here
	void CEngine::RunGame()
	{
		/**
		 * After systems had been initialized, we enter
		 * in the main game loop where all the operations
		 * takes place. This is controlled directly by the
		 * engine itself, leaving to the client the programming
		 * of the game logic and presentation, using the engine
		 * tools, classes and methods
		 */
		while(true)
		{

		}
	}

	void CEngine::Shutdown()
	{
		// finish subsystem in reverse order
		Display->Shutdown();
		EngineConfig->Shutdown();
	}
}
