#pragma once

#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Query);

    /// @brief 查询对象
    class Query : public Resource
    {
    public:
        /// @brief 查询类型
        enum class QueryType : GLenum
        {
            None = GL_NONE,
            SamplesPassed = GL_SAMPLES_PASSED,
            AnySamplesPassed = GL_ANY_SAMPLES_PASSED,
            AnySamplesPassedConservative = GL_ANY_SAMPLES_PASSED_CONSERVATIVE,
            TimeElapsed = GL_TIME_ELAPSED,
            Timestamp = GL_TIMESTAMP,
            PrimitivesGenerated = GL_PRIMITIVES_GENERATED,
            TransformFeedbackPrimitivesWritten = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
        };

        /// @brief 查询对象参数名
        enum class ParameterName : GLenum
        {
            Result = GL_QUERY_RESULT,
            ResultAvailable = GL_QUERY_RESULT_AVAILABLE,
            ResultNoWait = GL_QUERY_RESULT_NO_WAIT,
            Target = GL_QUERY_TARGET,
        };

        static bool is_query(GLuint id);

    private:
        QueryType m_type = QueryType::None;

    public:
        Query() = default;
        Query(QueryType type);
        Query(Query &&from);
        ~Query() override;

    public:
        Query &operator=(Query &&from);
        base::Int64 get_resource_type() const override;
        QueryType get_type() const;

    public:
        void create(QueryType type);
        void destroy();

    public:
        void begin();
        void end();
        void begin_indexed(GLuint index);
        void end_indexed(GLuint index);

    public:
        template <typename T>
        T get_parameter(ParameterName pname) const;
    };

} // namespace gl_wrapper
