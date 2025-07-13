#pragma once

#include "shader.hpp"
#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Program);

    /// @brief 着色器程序对象
    class Program : public Resource
    {
    public:
        static inline bool is_program(GLuint id) { return glIsProgram(id); }
        static inline void unuse() { glUseProgram(0); }

    public:
        inline Program() { create(); }
        inline Program(Program &&from) : Resource(std::move(from)) {}
        inline ~Program() override { destroy(); }
        BASE_DELETE_COPY_FUNCTION(Program);

    public:
        Program &operator=(Program &&from);
        inline base::Int64 get_resource_type() const { return static_cast<base::Int64>(ResourceType::Program); }
        inline void use() const { glUseProgram(m_id); }

    public:
        void create();
        void destroy();

    public:
        inline void attach_shader(const Shader &shader) { glAttachShader(m_id, shader.get_id()); }
        void link_program();

    public:
        inline GLint get_uniform_location(const std::string &name) const { return glGetUniformLocation(m_id, name.data()); }
        inline GLint get_attrib_location(const std::string &name) const { return glGetAttribLocation(m_id, name.data()); }
        template <typename T>
        void set_uniform(GLint location, T &&value);
        template <typename T>
        T get_uniform(GLint location);

    public:
        inline void set_parameter(GLenum pname, GLint value) { glProgramParameteri(m_id, pname, value); }
        GLint get_parameter(GLenum pname) const;
    };

} // namespace gl_wrapper
