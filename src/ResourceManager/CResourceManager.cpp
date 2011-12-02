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

			TRACE("Texture %s", temp_name.c_str());
		}
	}

	void CResourceManager::ReloadTilesets()
	{
		TRACE("Reloading animations...");

		TiXmlHandle handletmp = m_XMLHandle->FirstChild("resources").FirstChildElement("tilesets").FirstChildElement("tileset");
		m_XMLElement = handletmp.ToElement();

		for(m_XMLElement; m_XMLElement; m_XMLElement = m_XMLElement->NextSiblingElement())
		{
			// safe to extract XML attributes
			std::string tileset_name = m_XMLElement->Attribute("name");
			std::string tile_src = m_XMLElement->Attribute("src");
			std::string tile_format = m_XMLElement->Attribute("format");

			m_Resource_Tilesets[tileset_name].reset(new s_Tileset);
			m_Resource_Tilesets[tileset_name]->src = tile_src;
			m_Resource_Tilesets[tileset_name]->format = tile_format;

			TRACE("Getting tiles");

			// get frames for each animation
			TiXmlElement* frame_h = NULL;
			frame_h = m_XMLElement->FirstChildElement("tile");

			for(frame_h; frame_h; frame_h = frame_h->NextSiblingElement())
			{
				TRACE("Tile %s", frame_h->Attribute("name"));
				m_Resource_Tilesets[tileset_name]->tiles[frame_h->Attribute("name")] = s_Tile(atoi(frame_h->Attribute("x")),
								atoi(frame_h->Attribute("y")),
								atoi(frame_h->Attribute("width")),
								atoi(frame_h->Attribute("height")));
			}

			delete frame_h;
		}
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
			std::string anim_framerate = m_XMLElement->Attribute("framerate");

			m_Resource_Animations[temp_name].reset(new s_Animation);
			m_Resource_Animations[temp_name]->type = (anim_type == "texture") ? ANIM_TEXTURE : ANIM_TILE;
			m_Resource_Animations[temp_name]->frame_rate = atoi(m_XMLElement->Attribute("framerate"));

			// get frames for each animation
			TiXmlElement* frame_h = NULL;
			frame_h = m_XMLElement->FirstChildElement("frame");

			for(frame_h; frame_h; frame_h = frame_h->NextSiblingElement())
			{
				if(anim_type == "texture")
				{
					m_Resource_Animations[temp_name]->texture_frames.push_back(frame_h->Attribute("texture"));
				}
				else
				{
					s_AnimationTile animtile_tmp;

					animtile_tmp.tileset = frame_h->Attribute("tileset");
					animtile_tmp.tile = frame_h->Attribute("tile");

					m_Resource_Animations[temp_name]->tile_frames.push_back(animtile_tmp);
				}
			}

			delete frame_h;
		}
	}

	void CResourceManager::ReloadMaps()
	{
		TRACE("Reloading maps...");
	}

	S64 CResourceManager::LoadTexture(std::string name, U64 prev_resourceID)
	{
		std::map< std::string, boost::shared_ptr<s_Texture> >::const_iterator search_map;

		search_map = m_Resource_Textures.find(name);

		if(search_map != m_Resource_Textures.end())
		{
			// load texture in the texturemanager and register id for later destruction
			U64 texture_id = CDisplayCore::_Textures()->LoadTexture(m_Resource_Textures[name]->src, prev_resourceID);
			return texture_id;
		}
		else
		{
			TRACE("WARNING: texture '%s' not found!", name.c_str());
			return -1;
		}
	}

	S64 CResourceManager::LoadTile(std::string tileset, std::string tile)
	{
		std::map< std::string, boost::shared_ptr<s_Tileset> >::const_iterator search_map;

		search_map = m_Resource_Tilesets.find(tileset);

		if(search_map != m_Resource_Tilesets.end())
		{
			std::map< std::string, s_Tile >::const_iterator tile_map;

			tile_map = m_Resource_Tilesets[tileset]->tiles.find(tile);

			if(tile_map != m_Resource_Tilesets[tileset]->tiles.end())
			{
				// load texture in the texturemanager and register id for later destruction
				U64 texture_id = CDisplayCore::_Textures()->LoadTile(m_Resource_Tilesets[tileset]->src,
															m_Resource_Tilesets[tileset]->tiles[tile].posx,
															m_Resource_Tilesets[tileset]->tiles[tile].posy,
															m_Resource_Tilesets[tileset]->tiles[tile].width,
															m_Resource_Tilesets[tileset]->tiles[tile].height);
				return texture_id;

			}
			else
			{
				TRACE("WARNING: tile '%s' in tileset '%s' not found!", tile.c_str(), tileset.c_str());
				return -1;
			}
		}
		else
		{
			TRACE("WARNING: tileset '%s' not found!", tileset.c_str());
			return -1;
		}
	}
}
