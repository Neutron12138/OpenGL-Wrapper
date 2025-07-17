#pragma once

#include "texture_cube_map.hpp"

namespace gl_wrapper
{
    TextureCubeMap::TextureCubeMap(TextureCubeMap &&from) : Texture(std::move(from)) {}

    TextureCubeMap &TextureCubeMap::operator=(TextureCubeMap &&from)
    {
        Texture::operator=(std::move(from));
        return *this;
    }

    void TextureCubeMap::create() { Texture::create(TextureType::TextureCubeMap); }

    void TextureCubeMap::set_storage(GLsizei levels, InternalFormat internalformat, GLsizei width, GLsizei height)
    {
        glTextureStorage2D(m_id, levels, static_cast<GLenum>(internalformat), width, height);
    }

    void TextureCubeMap::set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                       GLsizei width, GLsizei height, GLsizei depth,
                                       BaseFormat format, DataType type, const void *pixels)
    {
        glTextureSubImage3D(m_id, level, xoffset, yoffset, zoffset, width, height, depth,
                            static_cast<GLenum>(format), static_cast<GLenum>(type), pixels);
    }

    void TextureCubeMap::set_sub_image(GLint level, GLint zoffset, GLsizei width, GLsizei height,
                                       BaseFormat format, DataType type, const void *pixels)
    {
        set_sub_image(level, 0, 0, zoffset, width, height, 1, format, type, pixels);
    }

} // namespace gl_wrapper
