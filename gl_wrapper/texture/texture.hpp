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

               /// @brief 纹理单元
        enum class TextureUnit : GLenum
        {
            Unit0 = GL_TEXTURE0,
            Unit1 = GL_TEXTURE1,
            Unit2 = GL_TEXTURE2,
            Unit3 = GL_TEXTURE3,
            Unit4 = GL_TEXTURE4,
            Unit5 = GL_TEXTURE5,
            Unit6 = GL_TEXTURE6,
            Unit7 = GL_TEXTURE7,
            Unit8 = GL_TEXTURE8,
            Unit9 = GL_TEXTURE9,
            Unit10 = GL_TEXTURE10,
            Unit11 = GL_TEXTURE11,
            Unit12 = GL_TEXTURE12,
            Unit13 = GL_TEXTURE13,
            Unit14 = GL_TEXTURE14,
            Unit15 = GL_TEXTURE15,
            Unit16 = GL_TEXTURE16,
            Unit17 = GL_TEXTURE17,
            Unit18 = GL_TEXTURE18,
            Unit19 = GL_TEXTURE19,
            Unit20 = GL_TEXTURE20,
            Unit21 = GL_TEXTURE21,
            Unit22 = GL_TEXTURE22,
            Unit23 = GL_TEXTURE23,
            Unit24 = GL_TEXTURE24,
            Unit25 = GL_TEXTURE25,
            Unit26 = GL_TEXTURE26,
            Unit27 = GL_TEXTURE27,
            Unit28 = GL_TEXTURE28,
            Unit29 = GL_TEXTURE29,
            Unit30 = GL_TEXTURE30,
            Unit31 = GL_TEXTURE31,
        };

        static bool is_texture(GLuint id);

    private:
        /// @brief 纹理类型
        TextureType m_type = TextureType::None;

    protected:
        /// @brief 纹理宽度
        base::Size m_width = 0;
        /// @brief 纹理高度
        base::Size m_height = 0;
        /// @brief 纹理深度
        base::Size m_depth = 0;
        /// @brief 内部格式
        InternalFormat m_internal_format = InternalFormat::None;

    public:
        Texture() = default;
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
        void active_unit(TextureUnit unit) const;

    public:
        base::Size get_width() const;
        base::Size get_height() const;
        base::Size get_depth() const;
        InternalFormat get_internal_format() const;

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
        void set_parameter(ParameterName pname, GLint param);
        void set_parameter(ParameterName pname, GLfloat param);
        void set_parameter(ParameterName pname, GLuint param);
        void get_parameter(ParameterName pname, GLint &param) const;
        void get_parameter(ParameterName pname, GLfloat &param) const;
        void get_parameter(ParameterName pname, GLuint &param) const;

        void set_border_color(const glm::vec4 &color);
        glm::vec4 get_border_color() const;

        template <typename T>
        T get_parameter(ParameterName pname) const
        {
            T result;
            get_parameter(pname, result);
            return result;
        }
    };

} // namespace gl_wrapper
