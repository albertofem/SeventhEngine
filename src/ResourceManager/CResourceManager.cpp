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
 * @since		2011.1026
 *
 */

#include <map>

#include "common.h"
#include "DisplayCore/CLayerManager.h"
#include "ResourceManager/CResourceManager.h"
#include "Engine/CEngine.h"

#include "tinyxml/tinyxml.h"

namespace Seventh
{
	class CLayerManager;

	CResourceManager::CResourceManager(std::string filename, CEngine* engine)
		: m_XMLFile(NULL), m_XMLNode(NULL), m_XMLAttr(NULL), m_XMLElement(NULL),
		m_Engine(engine)
	{
		m_XMLFile = new TiXmlDocument(filename.c_str());

		// clear maps
		m_Resource_Textures.clear();
		m_Resource_Tilesets.clear();
		m_Resource_Animations.clear();
		m_Resource_Maps.clear();
	}

	CResourceManager::~CResourceManager()
	{
		// delete all pointers to tinyxml structures
		delete m_XMLAttr;
		delete m_XMLElement;
		delete m_XMLHandle;
		delete m_XMLNode;
		delete m_XMLFile;
	}

	void CResourceManager::Start()
	{
		// first load the XML file
		m_XMLFile->LoadFile();

		// and get the xml handle
		m_XMLHandle = new TiXmlHandle(m_XMLFile);

		// load resource xml file
		ReloadAllResources();
	}

	void CResourceManager::ReloadAllResources()
	{
		// extract textures
		ReloadTextures();

		// extract tilesets
		ReloadTilesets();

		// extract animations
		ReloadAnimations();

		// extract maps
		ReloadMaps();
	}

	void CResourceManager::ReloadTextures()
	{
		// clear this resource map first
		m_Resource_Textures.clear();

		TRACE("Reloading textures...");

		// ok, time to look in the xml file for this stuff
		RecursiveReloadTextures(m_XMLElement);
	}

	void CResourceManager::RecursiveReloadTextures(TiXmlElement* xml_element)
	{
		if(xml_element == NULL)
		{
			// get to the first element
			m_XMLElement = m_XMLHandle->FirstChild("resources").FirstChildElement("textures").FirstChildElement("texture").ToElement();
		}
		else
		{
			m_XMLElement = xml_element->NextSiblingElement("texture");
		}

		if(m_XMLElement != NULL)
		{
			// safe to extract XML attributes
			std::string temp_name = m_XMLElement->Attribute("name");

			m_Resource_Textures[temp_name].reset(new s_Texture);

			// get attributes
			m_Resource_Textures[temp_name]->src = m_XMLElement->Attribute("src");
			m_Resource_Textures[temp_name]->format = m_XMLElement->Attribute("format");

			RecursiveReloadTextures(m_XMLElement);
		}
		else
		{
			// resource finished, nothing to do here
			return;
		}
	}

	void CResourceManager::ReloadTilesets()
	{
		TRACE("Reloading tilesets...");
	}

	void CResourceManager::ReloadAnimations()
	{
		TRACE("Reloading animations...");
	}

	void CResourceManager::ReloadMaps()
	{
		TRACE("Reloading maps...");
	}

	void CResourceManager::LoadTexture(std::string name)
	{
		std::map< std::string, boost::shared_ptr<s_Texture> >::const_iterator search_map;

		search_map = m_Resource_Textures.find(name);

		if(search_map != m_Resource_Textures.end())
		{
			// render texture
			m_Engine->_Display()->_Layers()->RegisterOverallTexture(name, m_Resource_Textures[name]->src);
		}
		else
		{
			TRACE("WARNING: texture '%s' not found!", name.c_str());
		}
	}
}
