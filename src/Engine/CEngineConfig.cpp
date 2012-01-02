/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
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
 * @version	0.1
 *
 */

#include <string>
#include <memory>

#include "Engine/CEngineConfig.h"

namespace Seventh
{
	/**
	 * Constructor, do nothing :(
	 */
	CEngineConfig::CEngineConfig()
	{
		// do nothing
	}

	/**
	 * Set the URL of file to load
	 *
	 * @param std:string filename
	 * @return void
	 */
	void CEngineConfig::setConfigFile(std::string filename)
	{
		m_ConfigFile = filename;
	}

	/**
	 * Start the config subsystem by
	 * initializing the IniParser module
	 *
	 * @return void
	 */
	void CEngineConfig::Start()
	{
		// reset and initialize the pointer
		m_IniHandler.reset(new INIReader(m_ConfigFile));

		// if we get an error, throw and engine exception
		if(m_IniHandler->ParseError() < 0)
		{
			TRACE("Trying to load .ini file '%s' failed\n", m_ConfigFile.c_str());
			throw seventh_engine_exception("Cannot load .ini configuration file", STH_EXCEPTION_CANNOT_LOAD_CONFIG_INI);
		}
	}

	/**
	 * Get a parameter from an specific
	 * configuration section, expressed
	 * as an integer
	 *
	 * @param std::string section
	 * @param std::string param
	 * @param S32 default_return Default int to return if
		this parameter was not found
	 */
	S64 CEngineConfig::getConfigValue_Int(std::string section, std::string param, S32 default_return)
	{
		return m_IniHandler->GetInteger(section, param, default_return);
	}

	/**
	 * Get a parameter from an specific
	 * configuration section, expressed
	 * as an std::string
	 *
	 * @param std::string section
	 * @param std::string param
	 * @param std::string default_return Default string to return if
		this parameter was not found
	 */
	std::string CEngineConfig::getConfigValue_String(std::string section, std::string param, std::string default_return)
	{
		return m_IniHandler->Get(section, param, default_return);
	}

	/**
	 * Get a parameter from an specific
	 * configuration section, expressed
	 * as a boolean. Defaults to false if
	 * the param is not found
	 *
	 * @param std::string section
	 * @param std::string param
	 */
	bool CEngineConfig::getConfigValue_Bool(std::string section, std::string param)
	{
		return m_IniHandler->GetBoolean(section, param, false);
	}

	/**
	 * This method is currently void, but
	 * is required by the CEngine class, and
	 * must be called even if its empty
	 */
	void CEngineConfig::Shutdown()
	{
		// do nothing
	}

	CEngineConfig::~CEngineConfig()
	{
		// implicit destruction of IniHandler
		// pointer manager by shared_ptr
	}
}
