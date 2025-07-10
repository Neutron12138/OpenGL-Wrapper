#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    class TextureCubeMap : public Texture
    {
    public:
        inline TextureCubeMap() : Texture(GL_TEXTURE_CUBE_MAP) {}
        inline ~TextureCubeMap() override = default;

    public:
        inline void create() { Texture::create(GL_TEXTURE_CUBE_MAP); }

    public:
        inline void tex_image2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                GLenum format, GLenum type, const void *pixels = nullptr)
        {
            glTexImage2D(target, level, internalformat, width, height, 0, format, type, pixels);
        }

        inline void tex_image2D(GLenum target, GLint internalformat, GLsizei width,
                                GLsizei height, GLenum format, const void *pixels = nullptr)
        {
            tex_image2D(target, 0, internalformat, width, height, format, GL_UNSIGNED_BYTE, pixels);
        }
    };

} // namespace gl_wrapper
