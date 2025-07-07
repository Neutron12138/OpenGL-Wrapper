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
    private:
        /// @brief 着色器类型
        GLenum m_type;

    public:
        inline Shader(GLenum type) : m_type(type)
        {
            m_id = glCreateShader(type);
            if (m_id == 0)
                throw BASE_MAKE_RUNTIME_ERROR(
                    "Failed to create Shader, type: ", type);
        }

        inline ~Shader() override { glDeleteShader(m_id); }

    public:
        inline GLenum get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Shader); }

    public:
        void shader_source(const std::string &source);
        void compile_shader();

    public:
        GLint get_parameter(GLenum pname) const;
        std::string get_source() const;
    };

} // namespace gl_wrapper
