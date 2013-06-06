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

#include "Common.h"

#ifndef _LOGGER_H_
#define _LOGGER_H_

namespace Seventh
{
	enum LogLevel 
	{
		LOG_DEBUG = 0x0,
		LOG_INFO = 0x1,
		LOG_WARN = 0x2,
		LOG_ERROR = 0x3,
		LOG_CRITICAL = 0x4
	};

	class Logger : public Singleton<Logger>, public AllocatedObject
	{
	public:
		Logger() {};
		~Logger() {};

		// log level methods
		void Debug(const std::string message, ...);
		void Info(const std::string message, ...);
		void Warn(const std::string message, ...);
		void Error(const std::string message, ...);
		void Critical(const std::string message, ...);

	protected:
		void printMessage(const LogLevel type, const std::string message, va_list custom_args);
		std::string mapEnumValues(const LogLevel type);

	protected:
		struct tm* mCurrentTime;
		time_t mNow;
	};
}

#endif