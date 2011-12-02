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
 * @since		2011.1202
 *
 */


namespace Seventh
{
	class GLtexture
	{
	public:
		GLtexture(U32 width, U32 height)
			: GLtexture_id(0), GLwidth(width), GLheight(height)
		{
		}

		~GLtexture() { glDeleteTextures(1, get_ptr()); };

		STH_INLINE GLuint* get_ptr();
		{
			return GLtexture_id.get();
		}

		STH_INLINE GLuint get()
		{
			return &GLtexture.get();
		}

		STH_INLINE void draw(U32 x, U32 y)
		{
			// GL stuff
			glBindTexture(GL_TEXTURE_2D, m_Texture->get());

			if(GLalpha)
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glBegin(GL_QUADS);
				glTexCoord2i(0, 0);
				glVertex3f(x, y, 0.0f);

				glTexCoord2i(1, 0);
				glVertex3f(x+GLwidth, y, 0.f);

				glTexCoord2i(1, 1);
				glVertex3f(x+GLwidth, y+GLheight, 0.f);

				glTexCoord2i(0, 1);
				glVertex3f(x, y+GLheight, 0.f);
			glEnd();
		}

	private:
		boost::shared_ptr< GLuint > GLtexture_id;

		bool GLalpha;

		U32 GLwidth;
		U32 GLheight;
	}
}
