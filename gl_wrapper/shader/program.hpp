#pragma once

#include "shader.hpp"
#include "../base/bindable.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Program);

    /// @brief 着色器程序对象
    class Program : public Bindable
    {
    public:
        inline Program() { create(); }
        inline Program(Program &&from) : Bindable(std::move(from)) {}
        inline ~Program() override { destroy(); }

    public:
        Program &operator=(Program &&from);
        inline base::Int64 get_resource_type() const { return static_cast<base::Int64>(ResourceType::Program); }
        inline void bind() const override { glUseProgram(m_id); }
        inline void unbind() const override { glUseProgram(0); }

    public:
        void create();
        void destroy();

    public:
        inline void attach_shader(const Shader &shader) { glAttachShader(m_id, shader.get_id()); }
        void link_program();

    public:
        inline GLuint get_uniform_location(const std::string &name) const { return glGetUniformLocation(m_id, name.data()); }
        inline GLuint get_attrib_location(const std::string &name) const { return glGetAttribLocation(m_id, name.data()); }

    public:
        inline void set_parameter(GLenum pname, GLint value) { glProgramParameteri(m_id, pname, value); }
        GLint get_parameter(GLenum pname) const;
    };

} // namespace gl_wrapper
