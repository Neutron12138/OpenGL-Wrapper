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
        void set_storage(GLsizei levels, InternalFormat internalformat, GLsizei width, GLsizei height);
        void set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width,
                           GLsizei height, GLsizei depth, BaseFormat format, DataType type, const void *pixels = nullptr);
        void set_sub_image(GLint level, GLint zoffset, GLsizei width, GLsizei height, BaseFormat format,
                           DataType type, const void *pixels = nullptr);
    };

} // namespace gl_wrapper
