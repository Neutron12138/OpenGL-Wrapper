#pragma once

#include "vertex_layout.hpp"

namespace gl_wrapper
{
    /// @brief 2D顶点
    class Vertex2D
    {
    public:
        /// @brief 位置
        glm::vec2 position;

    public:
        inline Vertex2D() = default;
        inline constexpr Vertex2D(const glm::vec2 &pos)
            : position(pos) {}
        inline ~Vertex2D() = default;
    };

    static_assert(sizeof(Vertex2D) == sizeof(glm::vec2), "Vertex layout error");

    template <>
    class VertexLayout<Vertex2D>
    {
    public:
        using VertexType = Vertex2D;

        static constexpr inline std::array<VertexAttrib, 1> ATTRIBUTES = {
            VertexAttrib{0, 2, DataType::Float, 0},
        };
    };

} // namespace gl_wrapper
