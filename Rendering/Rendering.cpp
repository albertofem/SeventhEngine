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

namespace Seventh
{
	template<> Rendering* Singleton<Rendering>::mInstance = 0;

	Rendering::Rendering()
	{
		LOG_INFO("Rendering: initialized");
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
	}

	bool Rendering::render()
	{
		if(glfwWindowShouldClose(mWindow))
			return false;

		mClock->reset();

		glfwPollEvents();

		if(mClock->step())
		{
			float ratio;
			int width, height;
			glfwGetFramebufferSize(mWindow, &width, &height);
			ratio = width / (float) height;
			glViewport(0, 0, width, height);
			glClear(GL_COLOR_BUFFER_BIT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
			glBegin(GL_TRIANGLES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-0.6f, -0.4f, 0.f);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.6f, -0.4f, 0.f);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(0.f, 0.6f, 0.f);
			glEnd();

			LOG_DEBUG("Swapping buffers");
			glfwSwapBuffers(mWindow);

			mClock->update();
		}

		return true;
	}

	void Rendering::shutdown()
	{
		LOG_INFO("Rendering: shutdown");
		
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}
}