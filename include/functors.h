/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.0816
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

}

#endif
