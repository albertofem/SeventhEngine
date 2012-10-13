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

#include <cassert>

namespace Seventh
{
	template < typename T > 
	class Singleton
	{
	private:
		Singleton(const Singleton<T> &);
		Singleton& operator=(const Singleton<T> &);

	protected:
		static T* mInstance;

	public:
		Singleton(void)
		{
			assert(!mInstance);
		}

		~Singleton(void)
		{
			assert(mInstance); 
			mInstance = 0;
		}

		static T& getInstance(void)
		{
			assert(mInstance); 
			return (*mInstance); 
		}

		static T* getInstancePtr(void)
		{
			return mInstance; 
		}
	};
}
