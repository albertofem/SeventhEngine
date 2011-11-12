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
		CTexture(std::string filename);

		~CTexture();

		void UpdateGameLogic();
		void Render();

		SDL_Surface* getSurfacePtr();

		bool loadResource();

	private:
		std::string m_ResourceFile;
		U32 m_TextureID;

		bool m_Draw;
		bool m_ResourceLoaded;

		SDL_Surface* m_Surface;
		SDL_Rect SDL_Coords;

		void Position(S32 pos_x, S32 pos_y);

		void inline SetTextureID(U32 texture_id)
		{
			m_TextureID = texture_id;
		}

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

	public:
		inline void SetDraw(bool set)
		{
			m_Draw = set;
		}

	friend class CTextureManager;
	};
}

#endif
