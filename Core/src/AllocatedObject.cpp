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

#include "AllocatedObject.h"

#define ABORT_ON_ASSERT_FAILURE 0
#include <nedmalloc.c>

namespace Seventh
{
	void* AllocatedObject::allocateBytes(size_t size)
	{
		void* ptr = nedalloc::nedmalloc(size);

		return ptr;
	}

	void AllocatedObject::deallocateBytes(void* ptr)
	{
		if(!ptr)
			return;

		nedalloc::nedfree(ptr);
	}
}