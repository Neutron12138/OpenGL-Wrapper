#pragma once

#include "../base/gl_loader.hpp"
#include "../base/enums.hpp"

namespace gl_wrapper
{
    /// @brief 顶点属性
    class VertexAttrib
    {
    public:
        /// @brief 属性索引
        const GLuint attrib_index;
        /// @brief 尺寸
        const GLint vertex_size;
        /// @brief 类型
        const DataType data_type;
        /// @brief 相对偏移量
        const GLuint relative_offset;

    public:
        inline constexpr VertexAttrib(GLuint index, GLint size, DataType type, GLuint offset)
            : attrib_index(index),
              vertex_size(size),
              data_type(type),
              relative_offset(offset) {}
        inline ~VertexAttrib() = default;
    };

} // namespace gl_wrapper
