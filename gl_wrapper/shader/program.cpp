#include "program.hpp"

namespace gl_wrapper
{
    Program &Program::operator=(Program &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    void Program::create()
    {
        destroy();
        m_id = glCreateProgram();
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create Program");
    }

    void Program::destroy()
    {
        glDeleteProgram(m_id);
        m_id = 0;
    }

    void Program::link_program()
    {
        glLinkProgram(m_id);

        GLint success = get_parameter(GL_LINK_STATUS);
        if (success)
            return;

        GLint length = get_parameter(GL_INFO_LOG_LENGTH);

        std::string info_log;
        info_log.resize(length);
        glGetProgramInfoLog(m_id, length, nullptr, info_log.data());
        throw BASE_MAKE_RUNTIME_ERROR(
            "Failed to link program, info log:\n",
            info_log);
    }

    GLint Program::get_parameter(GLenum pname) const
    {
        GLint value;
        glGetProgramiv(m_id, pname, &value);
        return value;
    }

} // namespace gl_wrapper
