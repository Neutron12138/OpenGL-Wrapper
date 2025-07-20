#pragma once

#include "vertex_attrib.hpp"
#include "vertex_layout.hpp"

namespace gl_wrapper
{
    /// @brief 3D顶点
    class Vertex3D
    {
    public:
        /// @brief 位置
        glm::vec3 position;

    public:
        inline Vertex3D() = default;
        inline constexpr Vertex3D(const glm::vec3 &pos)
            : position(pos) {}
        inline ~Vertex3D() = default;
    };

    static_assert(sizeof(Vertex3D) == sizeof(glm::vec3), "Vertex layout error");

    template <>
    class VertexLayout<Vertex3D>
    {
    public:
        using VertexType = Vertex3D;

        static constexpr inline std::array<VertexAttrib, 1> ATTRIBUTES = {
            VertexAttrib{0, 3, DataType::Float, 0},
        };
    };

} // namespace gl_wrapper
