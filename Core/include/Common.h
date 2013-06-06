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

#ifndef _COMMON_H_
#define _COMMON_H_

#include "Platform.h"

namespace Seventh
{
	/*
	 * Some types
	 */
	typedef unsigned char uchar;
	typedef unsigned short ushort;
	typedef unsigned int uint;
	typedef unsigned long ulong;
}

/*
 * Include STD headers and containers
 */

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

#include <vector>
#include <map>
#include <string>

#include <iostream>

/*
 * Project libraries
 */

#include "Singleton.h"
#include "AllocatedObject.h"
#include "Logger.h"

/*
 * Useful macros
 */

#define LOG_INFO(fmt, ...) Logger::get().Info(fmt, ##__VA_ARGS__);
#define LOG_ERROR(fmt, ...) Logger::get().Error(fmt, ##__VA_ARGS__);

#endif