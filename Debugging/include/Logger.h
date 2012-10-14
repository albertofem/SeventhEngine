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

#include <string>
#include <time.h>

#include "Singleton.h"

namespace Seventh
{
	enum LogType 
	{
		LOG_DEBUG = 0x0,
		LOG_INFO = 0x1,
		LOG_WARN = 0x2,
		LOG_ERROR = 0x3,
		LOG_CRITICAL = 0x4
	};

	class Logger : public Singleton<Logger>
	{
	public:
		Logger();
		~Logger();

		// log level methods
		void Debug(std::string message, ...);
		void Info(std::string message, ...);
		void Warn(std::string message, ...);
		void Error(std::string message, ...);
		void Critical(std::string message, ...);

	protected:
		void printMessage(LogType type, std::string message, ...);
		std::string mapEnumValues(LogType type);

	protected:
		struct tm* mCurrentTime;
		time_t mNow;
	};
}