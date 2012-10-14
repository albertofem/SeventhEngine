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

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include "Logger.h"

namespace Seventh
{
	template<> Logger* Singleton<Logger>::mInstance = 0;

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Info(std::string message, ...)
	{
		va_list args;
		va_start(args, message);

		printMessage(LOG_INFO, message);
	}

	void Logger::printMessage(LogType type, std::string message, ...)
	{
		va_list args;
		va_start(args, message);

		time(&mNow);
		mCurrentTime = localtime(&mNow);

		std::string message_type = mapEnumValues(type);
		std::string final_message = "[%i:%i:%i] [" + message_type + "] " + message + "\n";

		printf(final_message.c_str(), mCurrentTime->tm_hour, mCurrentTime->tm_min, mCurrentTime->tm_sec, args);
	}

	std::string Logger::mapEnumValues(LogType type)
	{
		switch(type)
		{
		case LOG_DEBUG:
			return "DEBUG";
			break;
		case LOG_INFO:
			return "INFO";
			break;
		case LOG_WARN:
			return "WARN";
			break;
		case LOG_ERROR:
			return "ERROR";
			break;
		case LOG_CRITICAL:
			return "CRITICAL";
			break;
		}
	}
}