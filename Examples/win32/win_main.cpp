/*
 * SeventhEngine
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
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "Core.h"
#include "Logger.h"

using namespace Seventh;

#ifdef _DEBUG
	int main(int argc, char* argv)
#else
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
{
	Logger* logger = new Logger;

	int running = GL_TRUE;

	if (!glfwInit())
		exit(EXIT_FAILURE);

	if (!glfwOpenWindow(300, 300, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	while (running)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 0);

		glfwSwapBuffers();

		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	}

	glfwTerminate();

	exit(EXIT_SUCCESS);
}