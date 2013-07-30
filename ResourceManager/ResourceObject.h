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

#include "Core/Common.h"

#ifndef _RESOURCE_OBJECT_H_
#define _RESOURCE_OBJECT_H_

namespace Seventh
{
	class ResourceObject : public AllocatedObject
	{
	public:
		ResourceObject() {}
		ResourceObject(std::string filename);
		~ResourceObject() {};

		virtual bool load() = 0;
		virtual void unload() = 0;

		bool isLoaded();
		std::string getFilename();
		std::string getName();
		uint getId();
		
	private:
		bool mLoaded;
		std::string mFilename;
		std::string mName;
		uint mID;
	};
}

#endif