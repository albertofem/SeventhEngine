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

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glfwSwapInterval(1); 		// Lock to vertical sync of monitor (normally 60Hz, so 60fps)
		glEnable(GL_SMOOTH);		// Enable (gouraud) shading
		glEnable(GL_DEPTH_TEST);	// Enable the depth testing
		glDepthFunc(GL_LEQUAL);		// Set our depth function to overwrite if new value less than or equal to current value
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Ask for nicest perspective correction
		glEnable(GL_TEXTURE_2D);
	}

	bool Rendering::render()
	{
		if(glfwWindowShouldClose(mWindow))
			return false;

		mClock->reset();

		if(mClock->step())
		{
			Texture* texture = new Texture("link.png");

			texture->load();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Reset the matrix
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			// Move things back into the screen
			glTranslatef(0.0f, 0.0f, -40.0f);

			// Rotate around the y-axis
			// Select the texture to use
			glBindTexture(GL_TEXTURE_2D, texture->getResource());

			float hsize = 15.0f; // Vertical size of the quad
			float vsize = 10.0f; // Vertical size of the quad

			// Draw our texture
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
			// Top left
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-hsize, -vsize, 0.0f);

			// Bottom left
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-hsize, vsize, 0.0f);

			// Bottom right
			glTexCoord2f(1.0, 1.0);
			glVertex3f(hsize, vsize, 0.0f);

			// Top right
			glTexCoord2f(1.0, 0.0);
			glVertex3f(hsize, -vsize, 0.0f);
			glEnd();
			glDisable(GL_TEXTURE_2D);

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