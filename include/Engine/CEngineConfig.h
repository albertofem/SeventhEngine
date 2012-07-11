/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
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
 * @version	0.1
 *
 */

#include <string>
#include <memory>

#include "common.h"

#include "INIReader/INIReader.h"

#ifndef STH_CENGINECONFIG_H_
#define STH_CENGINECONFIG_H_

namespace Seventh
{
	
/*
	 * CEngineConfig -- This class manages the basic
	 * configuration the engine will use in multiple
	 * ways; during initialization & runtime. It should
	 * not be used as a base class, and will be used both
	 * in the engine interal operations and in the end
	 * client interface (to access user-defined configuration)
	 *
	 * @author Alberto
	 * @since 1.0
	 */
	class CEngineConfig
	{
		// define IniPtr type to access the shared_ptr pointer
		typedef boost::shared_ptr<INIReader> IniPtr;

	public:
		
/*
		 * Ctor/dtor
		 */
		CEngineConfig();
		~CEngineConfig();

		
/*
		 * Getters, used by the client to access
		 * properties in the .ini file
		 */
		S64 getConfigValue_Int(std::string section, std::string param, S32 default_return);
		std::string getConfigValue_String(std::string section, std::string param, std::string default_return);
		bool getConfigValue_Bool(std::string section, std::string param);

		
/*
		 * (TODO) Setters
		 */
		void setConfigValue();

		
/*
		 * init and shutdown
		 */
		void Start();
		void Shutdown();

		
/*
		 * (TODO) Function used to change
		 * configuration file at runtime
		 */
		void setConfigFile(std::string filename);

	private:
		IniPtr m_IniHandler;
		std::string m_ConfigFile;
	};
}

#endif
