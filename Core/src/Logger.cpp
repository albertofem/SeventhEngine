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

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include "Logger.h"

namespace Seventh
{
	template<> Logger* Singleton<Logger>::mInstance = 0;

	void Logger::Info(const std::string message, ...)
	{
		va_list args;
		va_start(args, message);

		printMessage(LOG_INFO, message, args);
	}

	void Logger::Error(const std::string message, ...)
	{
		va_list args;
		va_start(args, message);

		printMessage(LOG_ERROR, message, args);
	}

	void Logger::printMessage(const LogLevel type, const std::string message, va_list custom_args)
	{
		time(&mNow);
		mCurrentTime = localtime(&mNow);

		std::string message_type = mapEnumValues(type);
		std::string final_message = "[" 
			+ std::to_string(mCurrentTime->tm_hour) + ":" 
			+ std::to_string(mCurrentTime->tm_min) + ":" 
			+ std::to_string(mCurrentTime->tm_sec) + "] [" + message_type + "] " + message + "\n";

		vprintf(final_message.c_str(), custom_args);
	}

	std::string Logger::mapEnumValues(const LogLevel type)
	{
		switch(type)
		{
		case LOG_DEBUG:
		default:
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