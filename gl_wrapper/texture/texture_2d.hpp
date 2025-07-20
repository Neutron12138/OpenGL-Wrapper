#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture2D);

    /// @brief 2D纹理
    class Texture2D : public Texture
    {
    public:
        Texture2D() = default;
        Texture2D(Texture2D &&from);
        ~Texture2D() override = default;
        BASE_DELETE_COPY_FUNCTION(Texture2D);

    public:
        Texture2D &operator=(Texture2D &&from);
        void create();

    public:
        void set_storage(GLsizei levels, InternalFormat internal_format, GLsizei width, GLsizei height);
        void set_sub_image(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                           PixelFormat format, DataType type, const void *pixels = nullptr);
        void set_sub_image(GLint level, GLsizei width, GLsizei height, PixelFormat format,
                           DataType type, const void *pixels = nullptr);
    };

    Texture2D create_texture_2d(
        base::Size levels, InternalFormat internal_format, base::Size width, base::Size height);

    Texture2D create_texture_2d(
        InternalFormat internal_format, base::Size width, base::Size height);

    Texture2D create_texture_2d_from_pixels(
        InternalFormat internal_format, base::Size width, base::Size height,
        PixelFormat format, DataType type, const void *pixels = nullptr, base::Size levels = 1);

    Texture2D create_texture_2d_from_pixels(
        InternalFormat internal_format, base::Size width, base::Size height,
        PixelFormat format, const void *pixels = nullptr, base::Size levels = 1);

} // namespace gl_wrapper
