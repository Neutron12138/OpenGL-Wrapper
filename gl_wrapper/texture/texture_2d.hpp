#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture2D);

    /// @brief 2D纹理资源
    class Texture2D : public Texture
    {
    public:
        Texture2D() : Texture(GL_TEXTURE_2D) {}
        ~Texture2D() override = default;

    public:
        inline void tex_image2D(GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                GLint border, GLenum format, GLenum type, const void *pixels)
        {
            glTexImage2D(get_type(), level, internalformat,
                         width, height, border, format, type, pixels);
        }

        inline void tex_image2D(GLint internalformat, GLsizei width,
                                GLsizei height, GLenum format, const void *pixels)
        {
            tex_image2D(0, internalformat, width, height, 0, format, GL_UNSIGNED_BYTE, pixels);
        }
    };

} // namespace gl_wrapper
