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
 * @author	Alberto Fernández <albertofem@gmail.com>
 */

/*
 * Very simple allocator abstraction, using nedmalloc
 */

#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

namespace Seventh
{
	class AllocatedObject
	{
	public:
		explicit AllocatedObject() {};
		~AllocatedObject() {}

		// new and deleted operators
		void* operator new(size_t size)
		{
			return allocateBytes(size);
		}

		void* operator new[] (size_t size)
		{
			return allocateBytes(size);
		}

		void operator delete (void* ptr)
		{
			deallocateBytes(ptr);
		}

		void operator delete[] (void* ptr)
		{
			deallocateBytes(ptr);
		}

	private:
		static void* AllocatedObject::allocateBytes(size_t size);
		static void AllocatedObject::deallocateBytes(void* ptr);
	};
}


#endif