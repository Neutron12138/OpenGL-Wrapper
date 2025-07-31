#pragma once

#include "sampler.hpp"

namespace gl_wrapper
{
    bool Sampler::is_sampler(GLuint id) { return glIsSampler(id); }
    void Sampler::unbind(GLuint unit) { glBindSampler(unit, 0); }

    Sampler::Sampler(Sampler &&from)
        : Resource(std::move(from)) {}

    Sampler::~Sampler() { destroy(); }

    Sampler &Sampler::operator=(Sampler &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    base::Int64 Sampler::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Sampler); }
    void Sampler::bind(GLuint unit) const { glBindSampler(unit, m_id); }

    void Sampler::create()
    {
        destroy();
        glCreateSamplers(1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_CLASS_RUNTIME_ERROR("Failed to create Sampler object");
    }

    void Sampler::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteSamplers(1, &m_id);
        m_id = 0;
    }

    void Sampler::set_wrap_s(WrapParameter wrap) { glSamplerParameteri(m_id, GL_TEXTURE_WRAP_S, static_cast<GLint>(wrap)); }
    void Sampler::set_wrap_t(WrapParameter wrap) { glSamplerParameteri(m_id, GL_TEXTURE_WRAP_T, static_cast<GLint>(wrap)); }
    void Sampler::set_wrap_r(WrapParameter wrap) { glSamplerParameteri(m_id, GL_TEXTURE_WRAP_R, static_cast<GLint>(wrap)); }
    void Sampler::set_min_filter(MinFilter filter) { glSamplerParameteri(m_id, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(filter)); }
    void Sampler::set_mag_filter(MagFilter filter) { glSamplerParameteri(m_id, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(filter)); }

    void Sampler::set_parameter(ParameterName pname, GLint param)
    {
        glSamplerParameteri(m_id, static_cast<GLenum>(pname), param);
    }

    void Sampler::set_parameter(ParameterName pname, GLuint param)
    {
        glSamplerParameteri(m_id, static_cast<GLenum>(pname), param);
    }

    void Sampler::set_parameter(ParameterName pname, GLfloat param)
    {
        glSamplerParameterf(m_id, static_cast<GLenum>(pname), param);
    }

    void Sampler::get_parameter(ParameterName pname, GLint &result) const
    {
        glGetSamplerParameteriv(m_id, static_cast<GLenum>(pname), &result);
    }

    void Sampler::get_parameter(ParameterName pname, GLfloat &result) const
    {
        glGetSamplerParameterfv(m_id, static_cast<GLenum>(pname), &result);
    }

    void Sampler::get_parameter(ParameterName pname, GLuint &result) const
    {
        glGetSamplerParameterIuiv(m_id, static_cast<GLenum>(pname), &result);
    }

    void Sampler::set_border_color(const glm::vec4 &color)
    {
        glSamplerParameterfv(m_id, GL_TEXTURE_BORDER_COLOR, reinterpret_cast<const GLfloat *>(&color));
    }

    glm::vec4 Sampler::get_border_color() const
    {
        glm::vec4 color;
        glGetSamplerParameterfv(m_id, GL_TEXTURE_BORDER_COLOR, reinterpret_cast<GLfloat *>(&color));
        return color;
    }

    Sampler create_sampler()
    {
        Sampler sampler;
        sampler.create();
        return sampler;
    }

    SamplerRef create_sampler_shared()
    {
        SamplerRef sampler = std::make_shared<Sampler>();
        sampler->create();
        return sampler;
    }

    SamplerUniqueRef create_sampler_unique()
    {
        SamplerUniqueRef sampler = std::make_unique<Sampler>();
        sampler->create();
        return sampler;
    }

    Sampler create_default_sampler()
    {
        Sampler sampler = create_sampler();
        sampler.set_wrap_s();
        sampler.set_wrap_t();
        sampler.set_wrap_r();
        sampler.set_min_filter();
        sampler.set_mag_filter();
        return sampler;
    }

    SamplerRef create_default_sampler_shared()
    {
        SamplerRef sampler = create_sampler_shared();
        sampler->set_wrap_s();
        sampler->set_wrap_t();
        sampler->set_wrap_r();
        sampler->set_min_filter();
        sampler->set_mag_filter();
        return sampler;
    }

    SamplerUniqueRef create_default_sampler_unique()
    {
        SamplerUniqueRef sampler = create_sampler_unique();
        sampler->set_wrap_s();
        sampler->set_wrap_t();
        sampler->set_wrap_r();
        sampler->set_min_filter();
        sampler->set_mag_filter();
        return sampler;
    }

} // namespace gl_wrapper
