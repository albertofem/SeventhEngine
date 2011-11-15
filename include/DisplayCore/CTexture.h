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
		CTexture(const CTexture& lhs);
		operator=(const CTexture& lhs);

		~CTexture();

		void UpdateGameLogic();
		void Render();

		SDL_Surface* GetSurfacePtr();

		bool LoadSurfaceMemory();

	private:
		std::string m_ResourceFile;

		bool m_Draw;
		bool m_ResourceLoaded;

		boost::shared_ptr< SDL_Surface > m_Surface;
		SDL_Rect SDL_Coords;

		void Position(S32 pos_x, S32 pos_y);

		static U64 m_TextureCounter;
		U64 m_TextureID;

	public:
		inline std::string GetSourceFile()
		{
			return m_ResourceFile;
		}

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

		inline U32 GetWidth()
		{
			return SDL_Coords.w;
		}

		inline U32 GetHeight()
		{
			return SDL_Coords.h;
		}

	friend class CTextureManager;
	};
}

#endif
