#pragma once

#include "../base/resource.hpp"
#include "../base/enums.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Texture);

    /// @brief 纹理对象
    class Texture : public Resource
    {
    public:
        /// @brief 纹理类型
        enum class TextureType : GLenum
        {
            None = GL_NONE,
            Texture1D = GL_TEXTURE_1D,
            Texture2D = GL_TEXTURE_2D,
            Texture3D = GL_TEXTURE_3D,
            Texture1DArray = GL_TEXTURE_1D_ARRAY,
            Texture2DArray = GL_TEXTURE_2D_ARRAY,
            TextureRectangle = GL_TEXTURE_RECTANGLE,
            TextureCubeMap = GL_TEXTURE_CUBE_MAP,
            TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
            TextureBuffer = GL_TEXTURE_BUFFER,
            Texture2DMultisample = GL_TEXTURE_2D_MULTISAMPLE,
            Texture2DMultisampleArray = GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
        };

        /// @brief 纹理参数名
        enum class ParameterName : GLenum
        {
            DepthStencilTextureMode = GL_DEPTH_STENCIL_TEXTURE_MODE,
            BaseLevel = GL_TEXTURE_BASE_LEVEL,
            CompareFunc = GL_TEXTURE_COMPARE_FUNC,
            CompareMode = GL_TEXTURE_COMPARE_MODE,
            LODBias = GL_TEXTURE_LOD_BIAS,
            MinFilter = GL_TEXTURE_MIN_FILTER,
            MagFilter = GL_TEXTURE_MAG_FILTER,
            MinLOD = GL_TEXTURE_MIN_LOD,
            MaxLOD = GL_TEXTURE_MAX_LOD,
            MaxLevel = GL_TEXTURE_MAX_LEVEL,
            SwizzleR = GL_TEXTURE_SWIZZLE_R,
            SwizzleG = GL_TEXTURE_SWIZZLE_G,
            SwizzleB = GL_TEXTURE_SWIZZLE_B,
            SwizzleA = GL_TEXTURE_SWIZZLE_A,
            WrapS = GL_TEXTURE_WRAP_S,
            WrapT = GL_TEXTURE_WRAP_T,
            WrapR = GL_TEXTURE_WRAP_R,

            BorderColor = GL_TEXTURE_BORDER_COLOR,
            SwizzleRGBA = GL_TEXTURE_SWIZZLE_RGBA,
        };

        /// @brief 缩小过滤器
        enum class MinFilter : GLenum
        {
            Nearest = GL_NEAREST,
            Linear = GL_LINEAR,
            NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
            LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
            NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
            LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
        };

        /// @brief 放大过滤器
        enum class MagFilter : GLenum
        {
            Nearest = GL_NEAREST,
            Linear = GL_LINEAR,
        };

        /// @brief 环绕参数
        enum class WrapParameter : GLenum
        {
            ClampToEdge = GL_CLAMP_TO_EDGE,
            ClampToBorder = GL_CLAMP_TO_BORDER,
            MirroredRepeat = GL_MIRRORED_REPEAT,
            Repeat = GL_REPEAT,
            MirrorClampToEdge = GL_MIRROR_CLAMP_TO_EDGE,
        };

        static bool is_texture(GLuint id);

    private:
        /// @brief 纹理类型
        TextureType m_type = TextureType::None;

    public:
        Texture() = default;
        Texture(TextureType type);
        Texture(Texture &&from);
        ~Texture() override;
        BASE_DELETE_COPY_FUNCTION(Texture);

    public:
        Texture &operator=(Texture &&from);
        TextureType get_type() const;
        base::Int64 get_resource_type() const override;
        void bind() const;
        void unbind() const;
        void bind_unit(GLuint unit) const;

    public:
        void create(TextureType type);
        void destroy();

    public:
        void generate_mipmap();
        void set_wrap_s(WrapParameter wrap = WrapParameter::Repeat);
        void set_wrap_t(WrapParameter wrap = WrapParameter::Repeat);
        void set_wrap_r(WrapParameter wrap = WrapParameter::Repeat);
        void set_min_filter(MinFilter filter = MinFilter::NearestMipmapLinear);
        void set_mag_filter(MagFilter filter = MagFilter::Linear);

    public:
        template <typename T>
        void set_parameter(ParameterName pname, T param);
        template <typename T>
        T get_parameter(ParameterName pname) const;
        void set_border_color(const glm::vec4 &color);
        glm::vec4 get_border_color() const;
    };

} // namespace gl_wrapper
