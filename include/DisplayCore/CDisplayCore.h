
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

#include <memory>

#include "common.h"
#include "Engine/CEngineConfig.h"
#include "DisplayCore/CCamera.h"

#include "Rendering/CRendering.h"

#ifndef STH_CDISPLAYCORE_H_
#define STH_CDISPLAYCORE_H_

namespace Seventh
{
	class CRendering;
	class CLayerManager;
	class CMapManager;


	class CDisplayCore
	{
	public:
		CDisplayCore(ENGINE_CONFIG& engine_config);
		~CDisplayCore();

		void Start();
		void Shutdown();

		// this method is implemented internally in each subsystem
		void UpdateGameLogic();

		// this method is only implemented by the display subsystem
		void Render();

	private:
		// prevent use of the default constructor
		CDisplayCore();

		void Init_Display();
		void Init_Layers();
		void Init_Textures();
		void Init_Animations();
		void Init_Maps();
		void Init_Movies();
		void Init_OpenGLContext();

		
/*
		 * display config
		 */
		U16 m_DisplayWidth;
		U16 m_DisplayHeight;
		U8 m_DisplayBPP;
		bool m_DisplayFScreen;

		
/*
		 * engine config
		 */
		ENGINE_CONFIG m_ENGINE_CONFIG;

		
/*
		 * rendering pipeline
		 */
		static CRendering RENDER_PIPELINE;

		
/*
		 * displays subsystems members
		 */
		static boost::shared_ptr<CLayerManager> Layers;

		
/*
		 * main surface
		 */
		static SDL_Surface* m_DisplayScreen;

	public:
		
/*
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

		static STH_INLINE SDL_Surface* _Screen()
		{
			return m_DisplayScreen;
		}

		static STH_INLINE void CleanScreen()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		static STH_INLINE CRendering& _Render()
		{
			return RENDER_PIPELINE;
		}
	};
}

#endif
