/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.0625
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
	/**
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
		/**
		 * Ctor/dtor
		 */
		CEngineConfig();
		~CEngineConfig();

		/**
		 * Getters, used by the client to access
		 * properties in the .ini file
		 */
		S64 getConfigValue_Int(std::string section, std::string param, S32 default_return);
		std::string getConfigValue_String(std::string section, std::string param, std::string default_return);
		bool getConfigValue_Bool(std::string section, std::string param);

		/**
		 * (TODO) Setters
		 */
		void setConfigValue();

		/**
		 * init and shutdown
		 */
		void Start();
		void Shutdown();

		/**
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
