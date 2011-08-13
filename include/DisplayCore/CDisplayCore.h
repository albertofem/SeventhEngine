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

#include <memory>

#include "common.h"
#include "./Engine/CEngineConfig.h"

#ifndef STH_CDISPLAYCORE_H_
#define STH_CDISPLAYCORE_H_

namespace Seventh
{
	class CDisplayCore
	{
	public:
		CDisplayCore(ENGINE_CONFIG& engine_config);
		~CDisplayCore();

		void Start() throw(seventh_displaycore_exception);
		void Shutdown() throw();

	private:
		// prevent use of the default constructor
		CDisplayCore();

		void Init_Display() throw(seventh_displaycore_exception);

		/**
		 * display config
		 */
		U16 m_DisplayWidth;
		U16 m_DisplayHeight;
		U8 m_DisplayBPP;
		bool m_DisplayFScreen;

		/**
		 * engine config
		 */
		ENGINE_CONFIG m_ENGINE_CONFIG;

		/**
		 * main surface layer
		 */
		SDL_Surface* m_DisplayScreen;
	};
}

#endif
