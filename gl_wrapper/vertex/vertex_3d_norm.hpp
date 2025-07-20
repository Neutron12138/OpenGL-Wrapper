#pragma once

#include "vertex_3d.hpp"

namespace gl_wrapper
{
    /// @brief 3D顶点
    class Vertex3DNorm : public Vertex3D
    {
    public:
        glm::vec3 normal;

    public:
        inline Vertex3DNorm() = default;
        inline constexpr Vertex3DNorm(const glm::vec3 &pos, const glm::vec3 &norm = {})
            : Vertex3D(pos), normal(norm) {}
        inline ~Vertex3DNorm() = default;
    };

    static_assert(sizeof(Vertex3DNorm) == 2 * sizeof(glm::vec3), "Vertex layout error");

    template <>
    class VertexLayout<Vertex3DNorm>
    {
    public:
        using VertexType = Vertex3DNorm;

        static constexpr inline std::array<VertexAttrib, 2> ATTRIBUTES = {
            VertexAttrib{0, 3, DataType::Float, 0},
            VertexAttrib{1, 3, DataType::Float, sizeof(glm::vec3)},
        };
    };

} // namespace gl_wrapper
