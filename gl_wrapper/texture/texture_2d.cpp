#pragma once

#include "texture_2d.hpp"

namespace gl_wrapper
{
    Texture2D::Texture2D(Texture2D &&from) : Texture(std::move(from)) {}

    Texture2D &Texture2D::operator=(Texture2D &&from)
    {
        Texture2D::operator=(std::move((from)));
        return *this;
    }

    void Texture2D::create() { Texture::create(TextureType::Texture2D); }

    void Texture2D::set_storage(GLsizei levels, InternalFormat internalformat, GLsizei width, GLsizei height)
    {
        glTextureStorage2D(m_id, levels, static_cast<GLenum>(internalformat), width, height);
    }

    void Texture2D::set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                  GLsizei height, BaseFormat format, DataType type, const void *pixels)
    {
        glTextureSubImage2D(m_id, level, xoffset, yoffset, width, height,
                            static_cast<GLenum>(format), static_cast<GLenum>(type), pixels);
    }

    void Texture2D::set_sub_image(GLint level, GLsizei width, GLsizei height,
                                  BaseFormat format, DataType type, const void *pixels)
    {
        set_sub_image(level, 0, 0, width, height, format, type, pixels);
    }

} // namespace gl_wrapper
