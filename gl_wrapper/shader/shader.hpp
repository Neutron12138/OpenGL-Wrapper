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
        /// @brief 着色器类型
        enum class ShaderType : GLenum
        {
            Compute = GL_COMPUTE_SHADER,
            Vertex = GL_VERTEX_SHADER,
            TessControl = GL_TESS_CONTROL_SHADER,
            TessEvaluation = GL_TESS_EVALUATION_SHADER,
            Geometry = GL_GEOMETRY_SHADER,
            Fragment = GL_FRAGMENT_SHADER,
        };

    private:
        /// @brief 着色器类型
        ShaderType m_type;

    public:
        inline Shader(ShaderType type) : m_type(type)
        {
            m_id = glCreateShader(static_cast<GLenum>(type));
            if (m_id == 0)
                throw BASE_MAKE_RUNTIME_ERROR(
                    "Failed to create Shader, type: ",
                    static_cast<base::Int32>(type));
        }

        inline ~Shader() override { glDeleteShader(m_id); }

    public:
        inline ShaderType get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Shader); }

    public:
        void shader_source(const std::string &source)
        {
            const char *source_ptr = source.data();
            glShaderSource(m_id, 1, &source_ptr, nullptr);
        }

        void compile_shader()
        {
            glCompileShader(m_id);

            GLint success;
            glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
            if (success)
                return;

            GLint length = 0;
            glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &length);

            std::string info_log;
            info_log.resize(length);
            glGetShaderInfoLog(m_id, length, nullptr, info_log.data());
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to compile shader, info log:\n",
                info_log);
        }
    };

} // namespace gl_wrapper
