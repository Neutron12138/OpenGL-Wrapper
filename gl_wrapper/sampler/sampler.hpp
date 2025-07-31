#pragma once

#include "../base/resource.hpp"
#include "../base/enums.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Sampler);

    class Sampler : public Resource
    {
    public:
        enum class ParameterName : GLenum
        {
            WrapS = GL_TEXTURE_WRAP_S,
            WrapT = GL_TEXTURE_WRAP_T,
            WrapR = GL_TEXTURE_WRAP_R,
            MinFilter = GL_TEXTURE_MIN_FILTER,
            MagFilter = GL_TEXTURE_MAG_FILTER,
            BorderColor = GL_TEXTURE_BORDER_COLOR,
            MinLOD = GL_TEXTURE_MIN_LOD,
            MaxLOD = GL_TEXTURE_MAX_LOD,
            LODBias = GL_TEXTURE_LOD_BIAS,
            CompareMode = GL_TEXTURE_COMPARE_MODE,
            CompareFunc = GL_TEXTURE_COMPARE_FUNC,
        };

        static bool is_sampler(GLuint id);
        static void unbind(GLuint unit);

    public:
        Sampler() = default;
        Sampler(Sampler &&from);
        ~Sampler() override;
        BASE_DELETE_COPY_FUNCTION(Sampler);

    public:
        Sampler &operator=(Sampler &&from);
        base::Int64 get_resource_type() const override;
        void bind(GLuint unit) const;

    public:
        void create();
        void destroy();

    public:
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

    Sampler create_sampler();
    SamplerRef create_sampler_shared();
    SamplerUniqueRef create_sampler_unique();

    Sampler create_default_sampler();
    SamplerRef create_default_sampler_shared();
    SamplerUniqueRef create_default_sampler_unique();

} // namespace gl_wrapper
