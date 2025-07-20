#pragma once

#include "vertex_3d.hpp"

namespace gl_wrapper
{
    /// @brief 3D顶点
    class Vertex3DTex : public Vertex3D
    {
    public:
        union
        {
            /// @brief 纹理坐标
            glm::vec2 tex_coord;
            /// @brief 纹理坐标
            glm::vec2 UV;
        };

    public:
        inline Vertex3DTex() = default;
        inline constexpr Vertex3DTex(const glm::vec3 &pos, const glm::vec2 &uv = {})
            : Vertex3D(pos), UV(uv) {}
        inline ~Vertex3DTex() = default;
    };

    static_assert(sizeof(Vertex3DTex) == sizeof(glm::vec3) + sizeof(glm::vec2), "Vertex layout error");

    template <>
    class VertexLayout<Vertex3DTex>
    {
    public:
        using VertexType = Vertex3DTex;

        static constexpr inline std::array<VertexAttrib, 2> ATTRIBUTES = {
            VertexAttrib{0, 3, DataType::Float, 0},
            VertexAttrib{1, 2, DataType::Float, sizeof(glm::vec3)},
        };
    };

} // namespace gl_wrapper
