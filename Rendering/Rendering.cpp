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

#include "Rendering.h"
#include "Clock.h"
#include "Texture.h"

namespace Seventh
{
	template<> Rendering* Singleton<Rendering>::mInstance = 0;

	Rendering::Rendering()
	{
		LOG_INFO("Rendering: initialized");

		ilutRenderer(ILUT_OPENGL);
		ilInit();
		iluInit();
		ilutInit();
		ilutRenderer(ILUT_OPENGL);

		mClock = new Clock;
	}

	Rendering::~Rendering()
	{
		shutdown();
	}

	bool Rendering::initialize(uint width, uint height, bool fullscreen, std::string window_title)
	{
		if(!glfwInit())
		{
			LOG_CRIT("Rendering: Cannot initialize GL context")
			return false;
		}

		mWindow = glfwCreateWindow(width, height, window_title.c_str(), fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

		if(!mWindow)
		{
			LOG_CRIT("Rendering: Cannot initialize GL window")

			shutdown();
			return false;
		}

		glfwMakeContextCurrent(mWindow);

		LOG_DEBUG("Rendering: window resolution, %dx%d, fullscreen: %d", width, height, fullscreen);

		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
		glOrtho(0, (GLsizei)width, (GLsizei)height, 0, 1, -1);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glfwSwapInterval(1);
		glEnable(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glDepthFunc(GL_LEQUAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		glEnable(GL_TEXTURE_2D);
		glLoadIdentity();
	}

	bool Rendering::render()
	{
		if(glfwWindowShouldClose(mWindow))
			return false;

		mClock->reset();

		if(mClock->step())
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			mClock->update();

			glfwSwapBuffers(mWindow);
		}

		glfwPollEvents();

		return true;
	}

	void Rendering::shutdown()
	{
		LOG_INFO("Rendering: shutdown");
		
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}

	GLFWwindow* Rendering::getCurrentWindow()
	{
		return mWindow;
	}
}