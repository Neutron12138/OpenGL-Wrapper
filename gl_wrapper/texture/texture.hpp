#pragma once

#include "../base/gl_resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture);

    /// @brief 纹理对象
    class Texture : public GLResource
    {
    public:
        /// @brief 纹理类型
        enum class TextureType : GLenum
        {
            Texture1D = GL_TEXTURE_1D,
            Texture1DArray = GL_TEXTURE_1D_ARRAY,
            Texture2D = GL_TEXTURE_2D,
            Texture2DArray = GL_TEXTURE_2D_ARRAY,
            Texture2DMultiSample = GL_TEXTURE_2D_MULTISAMPLE,
            Texture2DMultiSampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
            Texture3D = GL_TEXTURE_3D,
            TextureCubeMap = GL_TEXTURE_CUBE_MAP,
            TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
            TextureRectangle = GL_TEXTURE_RECTANGLE,
        };

        /// @brief 环绕方式
        enum class Wrap : GLenum
        {
            Repeat = GL_REPEAT,
            MirroredRepeat = GL_MIRRORED_REPEAT,
            ClampToEdge = GL_CLAMP_TO_EDGE,
            ClampToBorder = GL_CLAMP_TO_BORDER,
        };

        /// @brief 过滤方式
        enum class Filter : GLenum
        {
            Nearest = GL_NEAREST,
            Linear = GL_LINEAR,

            NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
            NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
            LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
            LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
        };

    private:
        /// @brief 纹理类型
        TextureType m_type;

    public:
        inline Texture(TextureType type) : m_type(type) { glGenTextures(1, &m_id); }
        inline ~Texture() override { glDeleteTextures(1, &m_id); }

    public:
        inline TextureType get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Texture); }

    public:
        inline void bind() { glBindTexture(static_cast<GLenum>(m_type), m_id); }
        inline void unbind() { glBindTexture(static_cast<GLenum>(m_type), 0); }
        inline void generate_mipmap() { glGenerateMipmap(static_cast<GLenum>(m_type)); }

        inline void set_wrap_s(Wrap wrap = Wrap::MirroredRepeat)
        {
            glTexParameteri(static_cast<GLenum>(m_type), GL_TEXTURE_WRAP_S, static_cast<GLenum>(wrap));
        }

        inline void set_wrap_t(Wrap wrap = Wrap::MirroredRepeat)
        {
            glTexParameteri(static_cast<GLenum>(m_type), GL_TEXTURE_WRAP_T, static_cast<GLenum>(wrap));
        }

        inline void set_wrap_r(Wrap wrap = Wrap::MirroredRepeat)
        {
            glTexParameteri(static_cast<GLenum>(m_type), GL_TEXTURE_WRAP_R, static_cast<GLenum>(wrap));
        }

        inline void set_min_filter(Filter filter = Filter::Linear)
        {
            glTexParameteri(static_cast<GLenum>(m_type), GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(filter));
        }

        inline void set_mag_filter(Filter filter = Filter::Linear)
        {
            glTexParameteri(static_cast<GLenum>(m_type), GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(filter));
        }
    };

} // namespace gl_wrapper
