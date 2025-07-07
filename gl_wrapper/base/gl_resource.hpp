#pragma once

#include <glm/glm.hpp>
#include <base/misc/resource.hpp>
#include "gl_loader.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(GLResource);

    /// @brief 基础OpenGL资源
    class GLResource : public base::Resource
    {
    public:
        /// @brief 资源类型
        enum class ResourceType : base::Int64
        {
            /// @brief 无
            None,
            /// @brief 缓冲区
            Buffer,
            /// @brief 顶点数组
            VertexArray,
            /// @brief 着色器
            Shader,
            /// @brief 着色器程序
            Program,
            /// @brief 纹理
            Texture,
        };

    protected:
        /// @brief 资源句柄ID
        GLuint m_id = 0;

    protected:
        inline GLResource() {}

    public:
        inline ~GLResource() override { m_id = 0; }

    public:
        inline GLuint get_id() const { return m_id; }
    };

} // namespace gl_wrapper
