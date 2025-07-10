#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture2D);

    /// @brief 2D纹理资源
    class Texture2D : public Texture
    {
    public:
        inline Texture2D() : Texture(GL_TEXTURE_2D) {}
        inline Texture2D(Texture2D &&from) : Texture(std::move(from)) {}

    public:
        inline void create() { Texture::create(GL_TEXTURE_2D); }

    public:
        inline void tex_image2D(GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                GLenum format, GLenum type, const void *pixels = nullptr)
        {
            glTexImage2D(get_type(), level, internalformat,
                         width, height, 0, format, type, pixels);
        }

        inline void tex_image2D(GLint internalformat, GLsizei width,
                                GLsizei height, GLenum format, const void *pixels = nullptr)
        {
            tex_image2D(0, internalformat, width, height, format, GL_UNSIGNED_BYTE, pixels);
        }
    };

} // namespace gl_wrapper
