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

#ifndef STH_CTEXTUREMANAGER_H_
#define STH_CTEXTUREMANAGER_H_

namespace Seventh
{
	class CTexture;

	class CTextureManager
	{
	public:
		CTextureManager();
		~CTextureManager();

		void UpdateGameLogic();
		void Render();

		U32 CreateTexture(std::string filename);
		void TransformTexture(U32 texture_id, STH_Transform &transform);

		void RenderTexture(U32 texture_id);

		void CleanScreen();

	private:
		// texture map
		std::map< U32, boost::shared_ptr<CTexture> > m_Textures;

		// textures ID
		U32 m_TextureCounter;

		// second surface to double buffer
		SDL_Surface* m_DBufferScreen;

		bool m_Clean;
	};
}

#endif
