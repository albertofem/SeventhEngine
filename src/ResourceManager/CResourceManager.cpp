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

#define TIXML_USE_TICPP

#include "common.h"
#include "DisplayCore/CLayerManager.h"
#include "ResourceManager/CResourceManager.h"
#include "Engine/CEngine.h"
#include "DisplayCore/CTextureManager.h"

#include "tinyxml/tinyxml.h"
#include "tinyxml/ticpp.h"

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
		m_XMLElement = m_XMLHandle->FirstChild("resources").FirstChildElement("textures").FirstChildElement("texture").ToElement();

		for(m_XMLElement; m_XMLElement; m_XMLElement = m_XMLElement->NextSiblingElement())
		{
			// safe to extract XML attributes
			std::string temp_name = m_XMLElement->Attribute("name");

			m_Resource_Textures[temp_name].reset(new s_Texture);

			// get attributes
			m_Resource_Textures[temp_name]->src = m_XMLElement->Attribute("src");
			m_Resource_Textures[temp_name]->format = m_XMLElement->Attribute("format");
			m_Resource_Textures[temp_name]->texture_id = -1;

			TRACE("Texture %s", temp_name.c_str());
		}
	}

	void CResourceManager::ReloadTilesets()
	{
		TRACE("Reloading tilesets...");
	}

	void CResourceManager::ReloadAnimations()
	{
		TRACE("Reloading animations...");

		TiXmlHandle handletmp = m_XMLHandle->FirstChild("resources").FirstChildElement("animations").FirstChildElement("animation");
		m_XMLElement = handletmp.ToElement();

		for(m_XMLElement; m_XMLElement; m_XMLElement = m_XMLElement->NextSiblingElement())
		{
			// safe to extract XML attributes
			std::string temp_name = m_XMLElement->Attribute("name");
			std::string anim_type = m_XMLElement->Attribute("type");

			TRACE("Animation %s - %s", temp_name.c_str(), anim_type.c_str());

			// get frames for each animation
			TiXmlElement* frame_h = NULL;
			frame_h = handletmp.FirstChildElement("frame").ToElement();

			for(frame_h; frame_h; frame_h = frame_h->NextSiblingElement())
			{
				if(anim_type == "texture")
				{
					// animation is texture-type
					m_Resource_Animations[temp_name].reset(new s_Animation);

					m_Resource_Animations[temp_name]->type = ANIM_TEXTURE;
					m_Resource_Animations[temp_name]->frame_rate = frame_h->Attribute("framerate");

					m_Resource_Animations[temp_name]->texture_frames.push_back(frame_h->Attribute("texture"));
				}
			}

			delete frame_h;
		}
	}

	void CResourceManager::ReloadMaps()
	{
		TRACE("Reloading maps...");
	}

	S64 CResourceManager::LoadTexture(std::string name)
	{
		std::map< std::string, boost::shared_ptr<s_Texture> >::const_iterator search_map;

		search_map = m_Resource_Textures.find(name);

		if(search_map != m_Resource_Textures.end())
		{

			// load texture in the texturemanager and register id for later destruction
			U64 texture_id = CDisplayCore::_Textures()->LoadTexture(m_Resource_Textures[name]->src);
						TRACE("Texture loaded with ID: %d", texture_id);
			return texture_id;
		}
		else
		{
			TRACE("WARNING: texture '%s' not found!", name.c_str());
			return -1;
		}
	}
}
