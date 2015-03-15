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

/*
 * Platform related stuff 
 */

#ifndef _PLATFORM_H_
#define _PLATFORM_H_

namespace Seventh
{
	#define SEVENTH_PLATFORM_WIN32 1
	#define SEVENTH_PLATFORM_LINUX 2

	/*
	 * Current platform calculation
	 */

	#if defined(__WIN32__) || defined(_WIN32)
		#define SEVENTH_PLATFORM SEVENTH_PLATFORM_WIN32
	#else
		#define SEVENTH_PLATFORM SEVENTH_PLATFORM_LINUX
	#endif

	/*
	 * Platform specific settings
	 */

	#if SEVENTH_PLATFORM == SEVENTH_PLATFORM_WIN32
		#define SEVENTH_INLINE __forceinline
		#define SEVENTH_EXPORT __declspec(dllexport)
	#else
		#define SEVENTH_INLINE inline
		#define SEVENTH_EXPORT
	#endif
}

#endif