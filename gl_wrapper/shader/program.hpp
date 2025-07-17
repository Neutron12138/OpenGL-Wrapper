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
        static Program link_shaders(const Shader &shader1, const Shader &shader2);
        static Program load_from_file(const std::string &vfilename, const std::string &ffilename);

    public:
        Program() = default;
        Program(const Shader &shader1, const Shader &shader2);
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
        template <typename T>
        void set_uniform(GLint location, const T &value);
        template <typename T>
        T get_uniform(GLint location);

    public:
        void set_parameter(ParameterName pname, GLint value);
        GLint get_parameter(ParameterName pname) const;
    };

} // namespace gl_wrapper
