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

#include "common.h"

#ifndef STH_CTEXTURE_H_
#define STH_CTEXTURE_H_

namespace Seventh
{

	class CTexture
	{
	public:
		CTexture();
		CTexture(std::string filename, const TextureCoord& coord);

		~CTexture();

		void UpdateGameLogic();
		void Render();

		SDL_Surface* getSurfacePtr();

		bool loadResource();

	private:
		std::string m_ResourceFile;
		U32 m_TextureID;

		TextureCoord m_TextureCoords;

		bool m_Draw;
		bool m_ResourceLoaded;

		SDL_Surface* m_Surface;

		SDL_Rect SDL_Coords;

	public:
		// getters
		inline bool needToDraw()
		{
			return m_Draw;
		}

		inline SDL_Rect getSDLRect()
		{
			return SDL_Coords;
		}
	};
}

#endif
