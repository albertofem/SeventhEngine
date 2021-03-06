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
 * @author	Alberto Fernández <albertofem@gmail.com>
 */

#include "Common.h"
#include "EngineComponent.h"
#include "Vendor/SimpleIni/SimpleIni.h"

#ifndef _ENGINECONFIG_H_
#define _ENGINECONFIG_H_

namespace Seventh
{
	class SeventhEngine;

	class EngineConfig : public EngineComponent<EngineConfig>
	{
	public:
		EngineConfig(SeventhEngine* engine, std::string configuration_file);
		~EngineConfig();

		long getIntFromSection(std::string section, std::string key, long default_value);
		bool getBoolFromSection(std::string section, std::string key, bool default_value);
		std::string getStringFromSection(std::string section, std::string key, std::string default_value);

		uint getScreenWidth();
		uint getScreenHeight();

		bool getFullScreen();
		std::string getGameTitle();

		CSimpleIniA* getIniReader();

	private:
		CSimpleIniA* mIniReader;
		uint mScreenWidth;
		uint mScreenHeight;
		bool mFullScreen;
		std::string mGameTitle;
	};
}

#endif