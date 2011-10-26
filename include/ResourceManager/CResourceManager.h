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
 * @since		2011.0816
 *
 */

#include <string>
#include <vector>
#include <map>

#include "tinyxml/tinyxml.h"
#include "resources.h"

#ifndef STH_CRESOURCEMANAGER_H_
#define STH_CRESOURCEMANAGER_H_

namespace Seventh
{
	class CEngine;
	class CResourceManager
	{
	public:
		CResourceManager(std::string filename, CEngine* engine);
		~CResourceManager();

		void LoadTexture(std::string name);
		void LoadMap(std::string name);
		void LoadTileFromTileset(std::string tileset, std::string name);
		void LoadAnimation(std::string name);

		void Start();

		/**
		 * This methods are used to reload
		 * everything from the xml file into
		 * the resource manager object
		 */
		void ReloadAllResources();

		void ReloadTextures();
		void ReloadTilesets();
		void ReloadAnimations();
		void ReloadMaps();

		/**
		 * This methods are for reloading of
		 * specific elements within the groups
		 * of resources (TODO)
		 */
		// void ReloadTexture(std::string);
		// void ReloadTileset(std::string);
		// ...

		/**
		 * Resource Getters
		 */
		s_Animation* GetTextureInfo(std::string name);

	private:
		CEngine* m_Engine;

		/**
		 * TinyXML++ specific members
		 */
		TiXmlDocument* m_XMLFile;
		TiXmlHandle* m_XMLHandle;

		// pointer to a XML attribute element
		TiXmlAttribute* m_XMLAttr;
		TiXmlElement* m_XMLElement;
		TiXmlNode* m_XMLNode;

		// resources xml file
		std::string m_ResourceXML;

		/**
		 * Maps to contain everything extracted
		 * from the xml resource file.
		 */
		std::map< std::string, boost::shared_ptr<s_Texture> > m_Resource_Textures;
		std::map< std::string, boost::shared_ptr<s_Tileset> > m_Resource_Tilesets;
		std::map< std::string, boost::shared_ptr<s_Animation> > m_Resource_Animations;
		std::map< std::string, boost::shared_ptr<s_Map> > m_Resource_Maps;

		/**
		 * Recursive resource loaders
		 */
		void RecursiveReloadTextures(TiXmlElement* xml_element);
	};
}

#endif