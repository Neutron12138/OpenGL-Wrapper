#pragma once

#include "vertex_3d_tex.hpp"

namespace gl_wrapper
{
    /// @brief 3D顶点
    class Vertex3DTexNorm : public Vertex3DTex
    {
    public:
        glm::vec3 normal;

    public:
        inline Vertex3DTexNorm() = default;
        inline constexpr Vertex3DTexNorm(const glm::vec3 &pos, const glm::vec2 &uv = {}, const glm::vec3 &norm = {})
            : Vertex3DTex(pos, uv), normal(norm) {}
        inline ~Vertex3DTexNorm() = default;
    };

    static_assert(sizeof(Vertex3DTexNorm) == 2 * sizeof(glm::vec3) + sizeof(glm::vec2), "Vertex layout error");

    template <>
    class VertexLayout<Vertex3DTexNorm>
    {
    public:
        using VertexType = Vertex3DTexNorm;

        static constexpr inline std::array<VertexAttrib, 3> ATTRIBUTES = {
            VertexAttrib{0, 3, DataType::Float, 0},
            VertexAttrib{1, 2, DataType::Float, sizeof(glm::vec3)},
            VertexAttrib{2, 3, DataType::Float, sizeof(glm::vec3) + sizeof(glm::vec2)},
        };
    };

} // namespace gl_wrapper
