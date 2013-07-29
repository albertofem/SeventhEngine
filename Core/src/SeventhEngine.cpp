/*
 * SeventhEngine
 *
 * Copyright (C) 2013 Alberto Fernández
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

#include "SeventhEngine.h"

#include "EngineConfig.h"

#include "GL/glfw.h"

namespace Seventh
{
	LogLevel logLevel = LogLevel::ERR;

	template<> SeventhEngine* Singleton<SeventhEngine>::mInstance = 0;

	SeventhEngine::SeventhEngine()
		: mLogger(0), mEngineConfig(0)
	{
		mLogger = new Logger();
		mEngineConfig = new EngineConfig("./engine.ini");
	}

	Logger* SeventhEngine::getLogger()
	{
		return mLogger;
	}

	SeventhEngine::~SeventhEngine()
	{
		delete mLogger;
		delete mEngineConfig;
	}

	Seventh::uint SeventhEngine::run()
	{
		int running = GL_TRUE;

		uint width = mEngineConfig->getScreenWidth();
		uint height = mEngineConfig->getScreenHeight();

		bool fullScreen = mEngineConfig->getFullScreen();

		LOG_DEBUG("Fullscreen: %d", fullScreen);

		if (!glfwInit())
			return 0x255;

		if (!glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, fullScreen ? GLFW_FULLSCREEN : GLFW_WINDOW))
		{
			glfwTerminate();
			return 0x255;
		}

		LOG_INFO("Ready to run main game loop")

		while (running)
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

}