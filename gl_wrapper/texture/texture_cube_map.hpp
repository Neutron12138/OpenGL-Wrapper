#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(TextureCubeMap);

    /// @brief 立方体贴图纹理
    class TextureCubeMap : public Texture
    {
    public:
        TextureCubeMap() = default;
        TextureCubeMap(TextureCubeMap &&from);
        ~TextureCubeMap() override = default;
        BASE_DELETE_COPY_FUNCTION(TextureCubeMap);

    public:
        TextureCubeMap &operator=(TextureCubeMap &&from);
        void create();

    public:
        void set_storage(GLsizei levels, InternalFormat internal_format, GLsizei width, GLsizei height);
        void set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                           GLsizei height, GLsizei depth, PixelFormat format, DataType type, const void *pixels);
        void set_sub_image(GLint level, GLint zoffset, GLsizei width, GLsizei height, PixelFormat format,
                           DataType type, const void *pixels);
    };

    TextureCubeMap create_texture_cube_map(
        base::Size levels, InternalFormat internal_format, base::Size width, base::Size height);

    TextureCubeMap create_texture_cube_map(
        InternalFormat internal_format, base::Size width, base::Size height);

} // namespace gl_wrapper
