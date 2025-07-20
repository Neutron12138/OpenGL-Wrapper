#pragma once

#include "texture_2d.hpp"

namespace gl_wrapper
{
    Texture2D::Texture2D(Texture2D &&from)
        : Texture(std::move(from)) {}

    Texture2D &Texture2D::operator=(Texture2D &&from)
    {
        Texture::operator=(std::move((from)));
        return *this;
    }

    void Texture2D::create() { Texture::create(TextureType::Texture2D); }

    void Texture2D::set_storage(GLsizei levels, InternalFormat internal_format, GLsizei width, GLsizei height)
    {
        if (m_internal_format != InternalFormat::None)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to modify the internal format of the texture");

        m_internal_format = internal_format;
        m_width = width;
        m_height = height;
        m_depth = 1;
        glTextureStorage2D(m_id, levels, static_cast<GLenum>(internal_format), width, height);
    }

    void Texture2D::set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                  GLsizei height, PixelFormat format, DataType type, const void *pixels)
    {
        glTextureSubImage2D(m_id, level, xoffset, yoffset, width, height,
                            static_cast<GLenum>(format), static_cast<GLenum>(type), pixels);
    }

    void Texture2D::set_sub_image(GLint level, GLsizei width, GLsizei height,
                                  PixelFormat format, DataType type, const void *pixels)
    {
        set_sub_image(level, 0, 0, width, height, format, type, pixels);
    }

    Texture2D create_texture_2d_from_pixels(
        InternalFormat internal_format, base::Size width, base::Size height,
        PixelFormat format, DataType type, const void *pixels)
    {
        Texture2D texture;
        texture.create();
        texture.set_storage(1, internal_format, width, height);
        texture.set_sub_image(0, width, height, format, type, pixels);
        texture.set_wrap_s();
        texture.set_wrap_t();
        texture.set_min_filter();
        texture.set_mag_filter();

        return std::move(texture);
    }

    Texture2D create_texture_2d_from_pixels(
        InternalFormat internal_format, base::Size width, base::Size height,
        PixelFormat format, const void *pixels)
    {
        return create_texture_2d_from_pixels(internal_format, width, height, format, DataType::UnsignedByte, pixels);
    }

} // namespace gl_wrapper
