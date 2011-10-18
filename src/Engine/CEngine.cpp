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
	boost::shared_ptr<CClock> CEngine::Clock = CClock::getInstance();
	bool CEngine::s_Running = true;

	CEngine::CEngine()
	{
		// empty constructor, user must call the "Initialize()"
		// method in order to start the engine
	}

	CEngine::~CEngine()
	{
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

		/**
		 * start events core
		 */
		Events.reset(new CEventsCore(this));
		Events->Start();

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

		// local variable for the main loop, to force clients
		// to use the signal system in order to stop the engine
		bool running = true;

		// events
		SDL_Event event;

		// set first measure of the internal clock
		Clock->init();

		// main game loop
		while(running)
		{
			Clock->reset();

			/**
			 * events loop; loop for queued
			 * events and register in the events
			 * core class for future handling
			 */
			while(SDL_PollEvent(&event))
			{
				Events->RegisterEvent(event);
			}

			while(Clock->logic())
			{

				// do update game logic
				UpdateGameLogic();

				// update clock
				Clock->update();
			}

			// remove events from the queue
			Events->RemoveEvents();

			// render
			RenderGame();

			// stop loop in the static variable has
			// been modified
			if(s_Running != true)
			{
				running = false;
			}

		}

		Shutdown();
	}

	void CEngine::sendSignal(const ENGINE_SIGNAL signal)
	{
		switch(signal)
		{
		case STOP_ENGINE:
			s_Running = false;
			TRACE("Received signal to stop engine!");
			break;

		}
	}

	void CEngine::Shutdown()
	{
		// finish subsystem in reverse order
		Gameplay->Shutdown();
		Display->Shutdown();
		EngineConfig->Shutdown();
		Events->Shutdown();
	}

	void CEngine::UpdateGameLogic() throw()
	{
		// update different subsystems game logic
		Display->UpdateGameLogic();
	}

	void CEngine::RenderGame() throw()
	{
		Display->Render();
	}
}
