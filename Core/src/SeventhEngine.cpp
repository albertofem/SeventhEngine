/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
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
 */

#include "GL/glfw.h"

#include "SeventhEngine.h"
#include "EngineConfig.h"
#include "ResourceManager/ResourceManager.h"
#include "Game.h"
#include "SceneManager/SceneManager.h"

namespace Seventh
{
	LogLevel logLevel = LogLevel::DEBUG;

	template<> SeventhEngine* Singleton<SeventhEngine>::mInstance = 0;

	SeventhEngine::SeventhEngine()
	{
		mLogger = new Logger(this);
		mEngineConfig = new EngineConfig(this, "./engine.cfg");
		mResourceManager = new ResourceManager(this);
	}

	Logger* SeventhEngine::getLogger()
	{
		return mLogger;
	}

	SeventhEngine::~SeventhEngine()
	{
		delete mResourceManager;
		delete mEngineConfig;
		delete mLogger;
	}

	Seventh::uint SeventhEngine::run()
	{
		int running = GL_TRUE;

		uint width = mEngineConfig->getScreenWidth();
		uint height = mEngineConfig->getScreenHeight();

		bool fullScreen = mEngineConfig->getFullScreen();

		LOG_DEBUG("Fullscreen: %d", fullScreen);

		if(!glfwInit())
			return 0x255;

		if(!glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, fullScreen ? GLFW_FULLSCREEN : GLFW_WINDOW))
		{
			glfwTerminate();
			return 0x255;
		}

		glfwSetWindowTitle(mEngineConfig->getGameTitle().c_str());

		LOG_INFO("Ready to run main game loop")

		while(running)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 0);

			glfwSwapBuffers();

			running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
		}

		glfwTerminate();

		return 0x1;
	}

	EngineConfig* SeventhEngine::getEngineConfig()
	{
		return mEngineConfig;
	}

	bool SeventhEngine::loadGame(Game* game)
	{
		LOG_INFO("Loaded game '%s'", game->getName().c_str());

		game->setEngine(this);

		return true;
	}

	SceneManager* SeventhEngine::getSceneManager()
	{
		return mSceneManager;
	}
 }