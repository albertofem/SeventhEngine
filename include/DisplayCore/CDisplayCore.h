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
#include "Engine/CEngineConfig.h"
#include "DisplayCore/CCamera.h"

#ifndef STH_CDISPLAYCORE_H_
#define STH_CDISPLAYCORE_H_

namespace Seventh
{
	class CLayerManager;
	class CTextureManager;
	class CMapManager;

	class CDisplayCore
	{
	public:
		CDisplayCore(ENGINE_CONFIG& engine_config);
		~CDisplayCore();

		void Start() throw(seventh_displaycore_exception);
		void Shutdown() throw();

		// this method is implemented internally in each subsystem
		void UpdateGameLogic() throw();

		// this method is only implemented by the display subsystem
		void Render();

	private:
		// prevent use of the default constructor
		CDisplayCore();

		void Init_Display() throw(seventh_displaycore_exception);
		void Init_Layers() throw(seventh_displaycore_exception);
		void Init_Textures() throw(seventh_displaycore_exception);
		void Init_Animations() throw(seventh_displaycore_exception);
		void Init_Maps() throw(seventh_displaycore_exception);
		void Init_Movies() throw(seventh_displaycore_exception);
		void Init_OpenGLContext();

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
		 * displays subsystems members
		 */
		static boost::shared_ptr<CLayerManager> Layers;
		static boost::shared_ptr<CTextureManager> Textures;
		//static boost::shared_ptr<CObjectManager> Objects;
		//static boost::shared_ptr<CAnimationManager> Animations;
		static boost::shared_ptr<CMapManager> Maps;
		//static boost::shared_ptr<CMovieManager> Movies;

		/**
		 * main surface
		 */
		static SDL_Surface* m_DisplayScreen;

	public:
		/**
		 * Camera
		 */
		static boost::shared_ptr<CCamera> m_CurrentCamera;

		static CCamera* _Camera()
		{
			return m_CurrentCamera.get();
		}

		static void SetCurrentCamera(CCamera* camera)
		{
			m_CurrentCamera.reset(camera);
		}

	public:
		// STH_INLINE getters
		static STH_INLINE boost::shared_ptr<CLayerManager> _Layers()
		{
			return Layers;
		}

		static STH_INLINE boost::shared_ptr<CTextureManager> _Textures()
		{
			return Textures;
		}

		static STH_INLINE SDL_Surface* _Screen()
		{
			return m_DisplayScreen;
		}

		static STH_INLINE void CleanScreen()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	};
}

#endif
