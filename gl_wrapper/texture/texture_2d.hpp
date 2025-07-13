#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture2D);

    /// @brief 2D纹理
    class Texture2D : public Texture
    {
    public:
        inline Texture2D() : Texture(GL_TEXTURE_2D) {}
        inline Texture2D(Texture2D &&from) : Texture(std::move(from)) {}
        inline ~Texture2D() override = default;
        BASE_DELETE_COPY_FUNCTION(Texture2D);

    public:
        inline void create() { Texture::create(GL_TEXTURE_2D); }

    public:
        inline void set_storage(GLsizei levels, GLint internalformat, GLsizei width, GLsizei height)
        {
            glTextureStorage2D(m_id, levels, internalformat, width, height);
        }

        inline void set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
        {
            glTextureSubImage2D(m_id, level, xoffset, yoffset, width, height, format, type, pixels);
        }
    };

} // namespace gl_wrapper
