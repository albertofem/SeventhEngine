/*
 * SeventhEngine
 *
 * Copyright (C) 2013 Alberto Fern�ndez
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
 * @author	Alberto Fern�ndez <albertofem@gmail.com>
 */

#include "Core/Common.h"

#include "ResourceObject.h"

#ifndef _RESOURCE_H_
#define _RESOURCE_H_

namespace Seventh
{
	enum ResourceType;

	class Resource : public ResourceObject
	{
	public:
		Resource();
		~Resource();

		ResourceType getType();

	private:
		ResourceType mType;
	};
}

#endif