#pragma once

#include <string>
#include <base/core/exception.hpp>
#include "../base/gl_resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Shader);

    /// @brief 着色器对象
    class Shader : public GLResource
    {
    public:
        static inline bool is_shader(GLuint id) { return glIsShader(id); }

    private:
        /// @brief 着色器类型
        GLenum m_type = 0;

    public:
        inline Shader() = default;
        inline Shader(GLenum type) { create(type); }
        inline Shader(Shader &&from) : GLResource(std::move(from)), m_type(std::exchange(from.m_type, 0)) {}
        inline ~Shader() override { destroy(); }

    public:
        Shader &operator=(Shader &&from);
        inline GLenum get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Shader); }

    public:
        void create(GLenum type);
        void destroy();

    public:
        void set_source(const std::string &source);
        void compile_shader();

    public:
        GLint get_parameter(GLenum pname) const;
        std::string get_source() const;
    };

} // namespace gl_wrapper
