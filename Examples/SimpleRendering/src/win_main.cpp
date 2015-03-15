/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fern�ndez
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
 * @author Alberto Fern�ndez <albertofem@gmail.com>
 */

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include "Examples/SimpleRendering/SimpleRendering.h"

using namespace Seventh;

#ifdef WIN32 // main for console output in debug mode
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
	int main(int argc, char** argv)
#endif
{
	SET_LOG_LEVEL(LogLevel::DEBUG);

	SeventhEngine* engine = new SeventhEngine;
	SimpleRendering* simpleRendering = new SimpleRendering;

	if(engine->loadGame(simpleRendering))
	{
		return engine->run();
	}

	return 0x255;
}