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

#include "EngineConfig.h"

namespace Seventh
{
	template<> EngineConfig* Singleton<EngineConfig>::mInstance = 0;

	EngineConfig::EngineConfig(SeventhEngine* engine, std::string configuration_file)
		: EngineComponent<EngineConfig>(engine)
	{
		LOG_INFO("Initializing engine config subsystem")

		mIniReader = new CSimpleIniA;

		if(mIniReader->LoadFile(configuration_file.c_str()) < 0)
			LOG_WARN("Cannot parse engine configuration file: '%s'", configuration_file.c_str())
	}

	EngineConfig::~EngineConfig()
	{
		delete mIniReader;
	}

	long EngineConfig::getIntFromSection(std::string section, std::string key, long default_value)
	{
		return mIniReader->GetLongValue(section.c_str(), key.c_str(), default_value);
	}

	bool EngineConfig::getBoolFromSection(std::string section, std::string key, bool default_value)
	{
		return mIniReader->GetBoolValue(section.c_str(), key.c_str(), default_value);
	}

	std::string EngineConfig::getStringFromSection(std::string section, std::string key, std::string default_value)
	{
		return std::string(mIniReader->GetValue(section.c_str(), key.c_str(), default_value.c_str()));
	}

	uint EngineConfig::getScreenWidth()
	{
		if(mScreenWidth == NULL)
		{
			mScreenWidth = getIntFromSection("graphics", "width", 1024);
		}

		return mScreenWidth;
	}

	uint EngineConfig::getScreenHeight()
	{
		if(mScreenHeight == NULL)
		{
			mScreenHeight = getIntFromSection("graphics", "height", 768);
		}

		return mScreenHeight;
	}

	bool EngineConfig::getFullScreen()
	{
		if(mFullScreen == NULL)
		{
			mFullScreen = getBoolFromSection("graphics", "fullscreen", false);
		}

		return mFullScreen;
	}

	std::string EngineConfig::getGameTitle()
	{
		if(mGameTitle == "")
		{
			mGameTitle = getStringFromSection("game", "title", "SeventhEngine game");
		}

		return mGameTitle;
	}

	CSimpleIniA* EngineConfig::getIniReader()
	{
		return mIniReader;
	}

}