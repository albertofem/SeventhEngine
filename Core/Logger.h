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
	class Logger : public Singleton<Logger>, public AllocatedObject
	{
	public:
		Logger();
		~Logger();

		// log level methods
		void Debug(const std::string message, ...);
		void Info(const std::string message, ...);
		void Warn(const std::string message, ...);
		void Error(const std::string message, ...);
		void Critical(const std::string message, ...);

		void setLogLevel(const LogLevel log_level);

	protected:
		void printMessage(const LogLevel type, const std::string message, va_list custom_args);
		std::string mapEnumValues(const LogLevel type);

		bool checkLogLevel(const LogLevel level);

	protected:
		struct tm* mCurrentTime;
		time_t mNow;
	};
}

#endif