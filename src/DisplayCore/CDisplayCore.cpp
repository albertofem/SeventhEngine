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

#include "common.h"

#include "DisplayCore/CTextureManager.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CDisplayCore.h"

namespace Seventh
{
	// initialize static members
	boost::shared_ptr<CLayerManager> CDisplayCore::Layers;
	boost::shared_ptr<CTextureManager> CDisplayCore::Textures;
	bool CDisplayCore::m_ClearScreen = true;

	SDL_Surface* CDisplayCore::m_DisplayScreen = NULL;

	CDisplayCore::CDisplayCore()
	{
	}

	CDisplayCore::CDisplayCore(ENGINE_CONFIG& engine_config) :
		m_DisplayWidth(0),
		m_DisplayHeight(0),
		m_DisplayBPP(0)
	{
		m_ENGINE_CONFIG = engine_config;
	}

	void CDisplayCore::Start() throw(seventh_displaycore_exception)
	{
		// get display values from the .ini config
		m_DisplayWidth = m_ENGINE_CONFIG->getConfigValue_Int("graphics", "display_width", -1);
		m_DisplayHeight = m_ENGINE_CONFIG->getConfigValue_Int("graphics", "display_height", -1);
		m_DisplayBPP = m_ENGINE_CONFIG->getConfigValue_Int("graphics", "display_bpp", -1);
		m_DisplayFScreen = m_ENGINE_CONFIG->getConfigValue_Bool("grahics", "display_fullscren");

		//TRACE("Getting width: %d, height: %d, bpp: %d", m_DisplayWidth, m_DisplayHeight, m_DisplayBPP);

		// if the values are wrong, throw an exception
		if(m_DisplayWidth == 0 or
			m_DisplayHeight == 0 or
			m_DisplayBPP == 0)
		{
			throw seventh_displaycore_exception("Wrong values for width/height/bpp in .ini config file", STH_EXCEPTION_WRONG_INI_VALUES);
		}

		// Init display
		Init_Display();
		Init_Layers();
		Init_Textures();
	}

	void CDisplayCore::Init_Display() throw(seventh_displaycore_exception)
	{
		// init SDL core layer
		if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
		{
			TRACE("Couldn't init SDL layer: %s", SDL_GetError());
			throw seventh_displaycore_exception("Couldn't init SDL layer", STH_EXCEPTION_CANNOT_LOAD_SDL);
		}

		// set video mode and the base display screen
		if((m_DisplayScreen = SDL_SetVideoMode(m_DisplayWidth, m_DisplayHeight, m_DisplayBPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
		{
			TRACE("Couldn't init SDL video mode: %s", SDL_GetError());
			throw new seventh_displaycore_exception("Couldn't init SDL video mode", STH_EXCEPTION_CANNOT_SET_VIDEOMODE);
		}

		// set window title
		SDL_WM_SetCaption("Simple Window", "Simple Window");

		// display basic subsystem is initialize, OK
		TRACE("Display base core initialized: %dx%d@%d bpp", m_DisplayWidth, m_DisplayHeight, m_DisplayBPP);
	}

	void CDisplayCore::Init_Layers() throw(seventh_displaycore_exception)
	{
		Layers.reset(new CLayerManager);
	}

	void CDisplayCore::Init_Textures() throw(seventh_displaycore_exception)
	{
		Textures.reset(new CTextureManager);
	}

	void CDisplayCore::Shutdown() throw()
	{
		SDL_Quit();
	}

	void CDisplayCore::UpdateGameLogic() throw()
	{

	}

	void CDisplayCore::Render()
	{
		Layers->Render();

		// render stuff from the texture subsystem
		Textures->Render();

		// swap buffers
		SDL_Flip(m_DisplayScreen);
	}

	CDisplayCore::~CDisplayCore()
	{
	}
}
