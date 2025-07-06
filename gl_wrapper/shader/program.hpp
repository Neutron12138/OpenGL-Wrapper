#pragma once

#include "shader.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Program);

    /// @brief 着色器程序对象
    class Program : public GLResource
    {
    public:
        static inline void unuse() { glUseProgram(0); }

    public:
        inline Program()
        {
            m_id = glCreateProgram();
            if (m_id == 0)
                throw BASE_MAKE_RUNTIME_ERROR("Failed to create Program");
        }

        inline ~Program() override { glDeleteProgram(m_id); }

    public:
        inline GLuint get_id() const { return m_id; }
        inline base::Int64 get_resource_type() const { return static_cast<base::Int64>(ResourceType::Program); }

    public:
        inline void use() { glUseProgram(m_id); }
        inline void attach_shader(const Shader &shader) { glAttachShader(m_id, shader.get_id()); }

        void link_program()
        {
            glLinkProgram(m_id);

            GLint success;
            glGetProgramiv(m_id, GL_LINK_STATUS, &success);
            if (success)
                return;

            GLint length;
            glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);

            std::string info_log;
            info_log.resize(length);
            glGetProgramInfoLog(m_id, length, nullptr, info_log.data());
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to link program, info log:\n",
                info_log);
        }

    public:
        inline GLuint get_uniform_location(const std::string &name) const { return glGetUniformLocation(m_id, name.data()); }
        inline GLuint get_attrib_location(const std::string &name) const { return glGetAttribLocation(m_id, name.data()); }
    };

} // namespace gl_wrapper
