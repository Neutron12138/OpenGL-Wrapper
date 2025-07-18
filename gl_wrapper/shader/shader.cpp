#pragma once

#include <base/misc/read_string.hpp>
#include "shader.hpp"

namespace gl_wrapper
{
    bool Shader::is_shader(GLuint id) { return glIsShader(id); }

    Shader Shader::load_from_string(ShaderType type, const std::string &source)
    {
        return std::move(Shader(type, source));
    }

    Shader Shader::load_from_file(ShaderType type, const std::string &filename)
    {
        return std::move(Shader(type, base::read_string_from_file(filename)));
    }

    Shader::Shader(ShaderType type, const std::string &source)
    {
        create(type);
        set_source(source);
        compile_shader();
    }

    Shader::Shader(Shader &&from) : Resource(std::move(from)),
                                    m_type(std::exchange(from.m_type, ShaderType::None)) {}
    Shader::~Shader() { destroy(); }

    Shader &Shader::operator=(Shader &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, ShaderType::None);
        return *this;
    }

    Shader::ShaderType Shader::get_type() const { return m_type; }
    base::Int64 Shader::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Shader); }

    void Shader::create(ShaderType type)
    {
        destroy();

        m_id = glCreateShader(static_cast<GLenum>(type));
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to create Shader object, type: ", static_cast<GLenum>(type));

        m_type = type;
    }

    void Shader::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteShader(m_id);
        m_id = 0;
        m_type = ShaderType::None;
    }

    void Shader::set_source(const std::string &source)
    {
        const char *source_ptr = source.data();
        glShaderSource(m_id, 1, &source_ptr, nullptr);
    }

    void Shader::compile_shader()
    {
        glCompileShader(m_id);

        GLint success = get_parameter(ParameterName::CompileStatus);
        if (success)
            return;

        GLint length = get_parameter(ParameterName::InfoLogLength);

        std::string info_log;
        info_log.resize(length);
        glGetShaderInfoLog(m_id, length, nullptr, info_log.data());
        throw BASE_MAKE_RUNTIME_ERROR(
            "Failed to compile shader, info log:\n", info_log);
    }

    GLint Shader::get_parameter(ParameterName pname) const
    {
        GLint value;
        glGetShaderiv(m_id, static_cast<GLenum>(pname), &value);
        return value;
    }

    std::string Shader::get_source() const
    {
        GLint length = get_parameter(ParameterName::SourceLength);
        std::string source;
        source.resize(length);
        glGetShaderSource(m_id, length, nullptr, source.data());
        return source;
    }

} // namespace gl_wrapper
