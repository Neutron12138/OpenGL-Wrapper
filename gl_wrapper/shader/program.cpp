#pragma once

#include "program.hpp"

namespace gl_wrapper
{
    bool Program::is_program(GLuint id) { return glIsProgram(id); }
    void Program::unuse() { glUseProgram(0); }

    Program::Program(Program &&from)
        : Resource(std::move(from)) {}

    Program::~Program() { destroy(); }

    Program &Program::operator=(Program &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    base::Int64 Program::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Program); }
    void Program::use() const { glUseProgram(m_id); }

    void Program::create()
    {
        destroy();

        m_id = glCreateProgram();
        if (m_id == 0)
            throw BASE_MAKE_CLASS_RUNTIME_ERROR("Failed to create Program object");
    }

    void Program::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteProgram(m_id);
        m_id = 0;
    }

    void Program::attach_shader(const Shader &shader) { glAttachShader(m_id, shader); }

    void Program::link_program()
    {
        glLinkProgram(m_id);

        GLint success = get_parameter(ParameterName::LinkStatus);
        if (success)
            return;

        GLint length = get_parameter(ParameterName::InfoLogLength);

        std::string info_log;
        info_log.resize(length);
        glGetProgramInfoLog(m_id, length, nullptr, info_log.data());
        throw BASE_MAKE_CLASS_RUNTIME_ERROR(
            "Failed to link program, info log:\n",
            info_log);
    }

    GLint Program::get_uniform_location(const std::string &name) const { return glGetUniformLocation(m_id, name.data()); }
    GLint Program::get_attrib_location(const std::string &name) const { return glGetAttribLocation(m_id, name.data()); }

    void Program::set_parameter(ParameterName pname, GLint value) { glProgramParameteri(m_id, static_cast<GLenum>(pname), value); }

    void Program::get_parameter(ParameterName pname, GLint &result) const
    {
        glGetProgramiv(m_id, static_cast<GLenum>(pname), &result);
    }

    GLint Program::get_parameter(ParameterName pname) const
    {
        GLint result;
        get_parameter(pname, result);
        return result;
    }

    Program create_program()
    {
        Program program;
        program.create();
        return program;
    }

    ProgramRef create_program_shared()
    {
        ProgramRef program = std::make_shared<Program>();
        program->create();
        return program;
    }

    ProgramUniqueRef create_program_unique()
    {
        ProgramUniqueRef program = std::make_unique<Program>();
        program->create();
        return program;
    }

    Program create_program_from_shaders(const Shader &shader)
    {
        Program program = create_program();
        program.attach_shader(shader);
        program.link_program();
        return program;
    }

    Program create_program_from_shaders(const Shader &shader1, const Shader &shader2)
    {
        Program program = create_program();
        program.attach_shader(shader1);
        program.attach_shader(shader2);
        program.link_program();
        return program;
    }

    Program create_program_from_shaders(const Shader &shader1, const Shader &shader2, const Shader &shader3)
    {
        Program program = create_program();
        program.attach_shader(shader1);
        program.attach_shader(shader2);
        program.attach_shader(shader3);
        program.link_program();
        return program;
    }

    Program create_program_from_file(const std::filesystem::path &vfilename,
                                     const std::filesystem::path &ffilename)
    {
        return create_program_from_shaders(
            create_shader_from_file(Shader::ShaderType::Vertex, vfilename),
            create_shader_from_file(Shader::ShaderType::Fragment, ffilename));
    }

    Program create_program_from_file(const std::filesystem::path &vfilename,
                                     const std::filesystem::path &ffilename,
                                     const std::filesystem::path &gfilename)
    {
        return create_program_from_shaders(
            create_shader_from_file(Shader::ShaderType::Vertex, vfilename),
            create_shader_from_file(Shader::ShaderType::Fragment, ffilename),
            create_shader_from_file(Shader::ShaderType::Geometry, gfilename));
    }

} // namespace gl_wrapper
