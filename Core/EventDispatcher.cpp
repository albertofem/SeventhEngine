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
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include "EventDispatcher.h"

namespace Seventh
{
	template<> EventDispatcher* Singleton<EventDispatcher>::mInstance = 0;

	EventDispatcher::EventDispatcher(SeventhEngine* engine)
		: EngineComponent(engine)
	{
	}

	Event* EventDispatcher::dispatch(std::string event_name, Event* event)
	{
		LOG_INFO("Dispatching event '%s'", event_name.c_str());

		if(event == NULL)
		{
			Event* event = new Event(event_name);
		}

		if(mListeners.find(event_name) == mListeners.end())
		{
			LOG_WARN("No listeners found for event '%s'", event_name.c_str());
			return event;
		}

		// iterate listeners to notify
		std::map<std::string, EventListener*>::const_iterator listeners;

		for(listeners = mListeners.begin(); listeners != mListeners.end(); listeners++)
		{
			if(listeners->first == event_name)
				listeners->second->onEvent(event);
		}

		return event;
	}

	void EventDispatcher::addListener(std::string event_name, EventListener* event_listener)
	{
		mListeners[event_name] = event_listener;
	}
}