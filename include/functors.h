
/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
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
 * @version	0.1
 *
 */

#include "events.h"

#ifndef STH_FUNCTORS_H_
#define STH_FUNCTORS_H_

namespace Seventh
{
	template< typename Key, typename T >
	void RenderMapContainer(std::map< Key, T > map)
	{
		// iterate maps and delete resources
		typename std::map< Key, T >::const_iterator it;

		for(it=map.begin(); it!=map.end(); it++)
		{
			map[it->first]->Render();
		}
	}

	template< typename Key, typename T >
	void OnEventGeneric(std::map< Key, T> map, EVENT_INFO& event)
	{
		typename std::map< Key, T>::const_iterator it;

		for(it=map.begin(); it!=map.end(); it++)
		{
			map[it->first]->OnEvent(event);
		}
	}

	template< typename Key, typename T >
	void UpdateGameLogicGeneric(std::map< Key, T > map)
	{
		// iterate maps and delete resources
		typename std::map< Key, T >::const_iterator it;

		for(it=map.begin(); it!=map.end(); it++)
		{
			map[it->first]->UpdateGameLogic();
		}
	}
}

#endif
