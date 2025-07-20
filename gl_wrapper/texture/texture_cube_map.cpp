#pragma once

#include "texture_cube_map.hpp"

namespace gl_wrapper
{
    TextureCubeMap::TextureCubeMap(TextureCubeMap &&from)
        : Texture(std::move(from)) {}

    TextureCubeMap &TextureCubeMap::operator=(TextureCubeMap &&from)
    {
        Texture::operator=(std::move(from));
        return *this;
    }

    void TextureCubeMap::create() { Texture::create(TextureType::TextureCubeMap); }

    void TextureCubeMap::set_storage(GLsizei levels, InternalFormat internal_format, GLsizei width, GLsizei height)
    {
        if (m_internal_format != InternalFormat::None)
            throw BASE_MAKE_RUNTIME_ERROR("Unable to modify the internal format of the texture");

        m_internal_format = internal_format;
        m_width = width;
        m_height = height;
        m_depth = 6;
        glTextureStorage2D(m_id, levels, static_cast<GLenum>(internal_format), width, height);
    }

    void TextureCubeMap::set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                       GLsizei width, GLsizei height, GLsizei depth,
                                       PixelFormat format, DataType type, const void *pixels)
    {
        glTextureSubImage3D(m_id, level, xoffset, yoffset, zoffset, width, height, depth,
                            static_cast<GLenum>(format), static_cast<GLenum>(type), pixels);
    }

    void TextureCubeMap::set_sub_image(GLint level, GLint zoffset, GLsizei width, GLsizei height,
                                       PixelFormat format, DataType type, const void *pixels)
    {
        set_sub_image(level, 0, 0, zoffset, width, height, 1, format, type, pixels);
    }

} // namespace gl_wrapper
