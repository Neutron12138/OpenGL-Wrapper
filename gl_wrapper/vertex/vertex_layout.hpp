#pragma once

#include <array>
#include <glm/glm.hpp>
#include "vertex_attrib.hpp"

namespace gl_wrapper
{
    /// @brief 顶点布局
    /// @tparam VertexT 顶点类型
    template <typename VertexT>
    class VertexLayout
    {
    public:
        using VertexType = VertexT;

        /// @brief 顶点属性列表
        static constexpr std::array<VertexAttrib, 0> ATTRIBUTES = {};
    };

} // namespace gl_wrapper
