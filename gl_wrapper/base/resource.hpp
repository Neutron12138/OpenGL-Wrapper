#pragma once

#include <base/misc/resource.hpp>
#include "gl_loader.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Resource);

    /// @brief OpenGL资源基类
    class Resource : public base::Resource
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
            /// @brief 帧缓冲
            Framebuffer,
            /// @brief 渲染缓冲
            Renderbuffer,
            /// @brief 采样器
            Sampler,
            /// @brief 查询
            Query,
        };

    protected:
        /// @brief 资源句柄ID
        GLuint m_id = 0;

    protected:
        inline Resource() = default;

    public:
        inline Resource(Resource &&from) : m_id(std::exchange(from.m_id, 0)) {}
        inline ~Resource() override { m_id = 0; }
        BASE_DELETE_COPY_FUNCTION(Resource);

    public:
        inline operator GLuint() const { return m_id; }
        inline GLuint get_id() const { return m_id; }
        inline bool is_valid() const override { return m_id; }
        inline virtual Resource &operator=(Resource &&from)
        {
            m_id = std::exchange(from.m_id, 0);
            return *this;
        }
    };

} // namespace gl_wrapper
