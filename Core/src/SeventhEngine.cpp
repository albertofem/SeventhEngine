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

#include "SeventhEngine.h"

namespace Seventh
{
	template<> SeventhEngine* Singleton<SeventhEngine>::mInstance = 0;

	SeventhEngine::SeventhEngine()
		: mLogger(0)
	{
		mLogger = new Logger();

		// load engine configuration
		json_value* engine_config = JSONParser::parseFile("engine.json");

		printf("%i x %i", engine_config->u.object.values[0].value->u.object.values[0].value->u.integer, 
			engine_config->u.object.values[0].value->u.object.values[1].value->u.integer);
	}

	Logger* SeventhEngine::getLogger()
	{
		return mLogger;
	}
}