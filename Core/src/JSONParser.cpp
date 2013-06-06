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

#include <fstream>
#include <sstream>

#include "JSONParser.h"

namespace Seventh
{
	json_value* JSONParser::parseFile(const std::string filename)
	{
		std::ifstream file(filename);

		if(!file)
		{
			LOG_ERROR("[JSONParser] Cannot open filename: %s", filename.c_str());
		}

		std::string file_contents;

		file_contents = static_cast<std::stringstream const&>(std::stringstream() << file.rdbuf()).str();

		LOG_INFO("[JSONParser] File contents: %s", file_contents.c_str());

		return json_parse(file_contents.c_str(), file_contents.size());
	}
}