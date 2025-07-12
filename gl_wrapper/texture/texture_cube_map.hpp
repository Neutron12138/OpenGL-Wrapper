#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(TextureCubeMap);

    /// @brief 立方体贴图纹理
    class TextureCubeMap : public Texture
    {
    public:
        inline TextureCubeMap() : Texture(GL_TEXTURE_CUBE_MAP) {}
        inline ~TextureCubeMap() override = default;

    public:
        inline void create() { Texture::create(GL_TEXTURE_CUBE_MAP); }

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
