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
        /// @brief 着色程序参数名
        enum class ParameterName : GLenum
        {
            DeleteStatus = GL_DELETE_STATUS,
            LinkStatus = GL_LINK_STATUS,
            ValidateStatus = GL_VALIDATE_STATUS,
            InfoLogLength = GL_INFO_LOG_LENGTH,
            AttachedShaders = GL_ATTACHED_SHADERS,
            ActiveAtomicCounterBuffers = GL_ACTIVE_ATOMIC_COUNTER_BUFFERS,
            ActiveAttributes = GL_ACTIVE_ATTRIBUTES,
            ActiveAttributeMaxLength = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
            ActiveUniforms = GL_ACTIVE_UNIFORMS,
            ActiveUniformBlocks = GL_ACTIVE_UNIFORM_BLOCKS,
            ActiveUniformBlockMaxNameLength = GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,
            ActiveUniformMaxLength = GL_ACTIVE_UNIFORM_MAX_LENGTH,
            ComputeWorkGroupSize = GL_COMPUTE_WORK_GROUP_SIZE,
            ProgramBinaryLength = GL_PROGRAM_BINARY_LENGTH,
            TransformFeedbackBufferMode = GL_TRANSFORM_FEEDBACK_BUFFER_MODE,
            TransformFeedbackVaryings = GL_TRANSFORM_FEEDBACK_VARYINGS,
            TransformFeedbackVaryingMaxLength = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,
            GeometryVerticesOut = GL_GEOMETRY_VERTICES_OUT,
            GeometryInputType = GL_GEOMETRY_INPUT_TYPE,
            GeometryOutputType = GL_GEOMETRY_OUTPUT_TYPE,
        };

        static bool is_program(GLuint id);
        static void unuse();

    public:
        Program() = default;
        Program(Program &&from);
        ~Program() override;
        BASE_DELETE_COPY_FUNCTION(Program);

    public:
        Program &operator=(Program &&from);
        base::Int64 get_resource_type() const;
        void use() const;

    public:
        void create();
        void destroy();

    public:
        void attach_shader(const Shader &shader);
        void link_program();

    public:
        GLint get_uniform_location(const std::string &name) const;
        GLint get_attrib_location(const std::string &name) const;

        // set uniform

        void set_uniform(GLint location, const GLint &value);
        void set_uniform(GLint location, const GLuint &value);
        void set_uniform(GLint location, const GLfloat &value);
        void set_uniform(GLint location, const GLdouble &value);

        void set_uniform(GLint location, const glm::ivec2 &value);
        void set_uniform(GLint location, const glm::uvec2 &value);
        void set_uniform(GLint location, const glm::vec2 &value);
        void set_uniform(GLint location, const glm::dvec2 &value);

        void set_uniform(GLint location, const glm::ivec3 &value);
        void set_uniform(GLint location, const glm::uvec3 &value);
        void set_uniform(GLint location, const glm::vec3 &value);
        void set_uniform(GLint location, const glm::dvec3 &value);

        void set_uniform(GLint location, const glm::ivec4 &value);
        void set_uniform(GLint location, const glm::uvec4 &value);
        void set_uniform(GLint location, const glm::vec4 &value);
        void set_uniform(GLint location, const glm::dvec4 &value);

        void set_uniform(GLint location, const glm::mat2 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat2x3 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat2x4 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat3 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat3x2 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat3x4 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat4 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat4x2 &value, GLboolean transpose = GL_FALSE);
        void set_uniform(GLint location, const glm::mat4x3 &value, GLboolean transpose = GL_FALSE);

        // get uniform

        void get_uniform(GLint location, GLint &result) const;
        void get_uniform(GLint location, GLuint &result) const;
        void get_uniform(GLint location, GLfloat &result) const;
        void get_uniform(GLint location, GLdouble &result) const;

        void get_uniform(GLint location, glm::ivec2 &result) const;
        void get_uniform(GLint location, glm::uvec2 &result) const;
        void get_uniform(GLint location, glm::vec2 &result) const;
        void get_uniform(GLint location, glm::dvec2 &result) const;

        void get_uniform(GLint location, glm::ivec3 &result) const;
        void get_uniform(GLint location, glm::uvec3 &result) const;
        void get_uniform(GLint location, glm::vec3 &result) const;
        void get_uniform(GLint location, glm::dvec3 &result) const;

        void get_uniform(GLint location, glm::ivec4 &result) const;
        void get_uniform(GLint location, glm::uvec4 &result) const;
        void get_uniform(GLint location, glm::vec4 &result) const;
        void get_uniform(GLint location, glm::dvec4 &result) const;

        void get_uniform(GLint location, glm::mat2 &result) const;
        void get_uniform(GLint location, glm::mat2x3 &result) const;
        void get_uniform(GLint location, glm::mat2x4 &result) const;
        void get_uniform(GLint location, glm::mat3 &result) const;
        void get_uniform(GLint location, glm::mat3x2 &result) const;
        void get_uniform(GLint location, glm::mat3x4 &result) const;
        void get_uniform(GLint location, glm::mat4 &result) const;
        void get_uniform(GLint location, glm::mat4x2 &result) const;
        void get_uniform(GLint location, glm::mat4x3 &result) const;

        template <typename T>
        T get_uniform(GLint location)
        {
            T result;
            get_uniform(location, result);
            return result;
        }

    public:
        void set_parameter(ParameterName pname, GLint value);
        void get_parameter(ParameterName pname, GLint &result) const;
        GLint get_parameter(ParameterName pname) const;
    };

    Program create_program_from_shaders(const Shader &shader1, const Shader &shader2);
    Program load_program_from_file(const std::string &vfilename, const std::string &ffilename);

} // namespace gl_wrapper
