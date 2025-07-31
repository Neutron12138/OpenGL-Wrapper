#pragma once

#include <string>
#include <base/core/exception.hpp>
#include <base/misc/read_from_file.hpp>
#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Shader);

    /// @brief 着色器对象
    class Shader : public Resource
    {
    public:
        /// @brief 着色器类型
        enum class ShaderType : GLenum
        {
            None = GL_NONE,
            Compute = GL_COMPUTE_SHADER,
            Vertex = GL_VERTEX_SHADER,
            TessControl = GL_TESS_CONTROL_SHADER,
            TessEvaluation = GL_TESS_EVALUATION_SHADER,
            Geometry = GL_GEOMETRY_SHADER,
            Fragment = GL_FRAGMENT_SHADER,
        };

        /// @brief 着色器参数名
        enum class ParameterName : GLenum
        {
            Type = GL_SHADER_TYPE,
            DeleteStatus = GL_DELETE_STATUS,
            CompileStatus = GL_COMPILE_STATUS,
            InfoLogLength = GL_INFO_LOG_LENGTH,
            SourceLength = GL_SHADER_SOURCE_LENGTH,
        };

        static bool is_shader(GLuint id);

    private:
        /// @brief 着色器类型
        ShaderType m_type = ShaderType::None;

    public:
        Shader() = default;
        Shader(Shader &&from);
        ~Shader() override;
        BASE_DELETE_COPY_FUNCTION(Shader);

    public:
        Shader &operator=(Shader &&from);
        ShaderType get_type() const;
        base::Int64 get_resource_type() const override;

    public:
        void create(ShaderType type);
        void destroy();

    public:
        void set_source(const std::string &source);
        void compile_shader();

    public:
        void get_parameter(ParameterName pname, GLint &result) const;
        GLint get_parameter(ParameterName pname) const;
        std::string get_source() const;
    };

    Shader create_shader(Shader::ShaderType type);
    ShaderRef create_shader_shared(Shader::ShaderType type);
    ShaderUniqueRef create_shader_unique(Shader::ShaderType type);

    Shader create_shader_from_string(Shader::ShaderType type, const std::string &source);
    Shader create_shader_from_file(Shader::ShaderType type, const std::filesystem::path &filename);

} // namespace gl_wrapper
