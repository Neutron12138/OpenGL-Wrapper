#include "shader.hpp"

namespace gl_wrapper
{
    void Shader::shader_source(const std::string &source)
    {
        const char *source_ptr = source.data();
        glShaderSource(m_id, 1, &source_ptr, nullptr);
    }

    void Shader::compile_shader()
    {
        glCompileShader(m_id);

        GLint success = get_parameter(GL_COMPILE_STATUS);
        if (success)
            return;

        GLint length = get_parameter(GL_INFO_LOG_LENGTH);

        std::string info_log;
        info_log.resize(length);
        glGetShaderInfoLog(m_id, length, nullptr, info_log.data());
        throw BASE_MAKE_RUNTIME_ERROR(
            "Failed to compile shader, info log:\n", info_log);
    }

    GLint Shader::get_parameter(GLenum pname) const
    {
        GLint value;
        glGetShaderiv(m_id, pname, &value);
        return value;
    }

    std::string Shader::get_source() const
    {
        GLint length = get_parameter(GL_SHADER_SOURCE_LENGTH);
        std::string source;
        source.resize(length);
        glGetShaderSource(m_id, length, nullptr, source.data());
        return std::move(source);
    }

} // namespace gl_wrapper
