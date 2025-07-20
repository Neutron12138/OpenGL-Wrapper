#pragma once

#include "vertex_2d.hpp"

namespace gl_wrapper
{
    class Vertex2DTex : public Vertex2D
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
        inline Vertex2DTex() = default;
        inline constexpr Vertex2DTex(const glm::vec2 &pos, const glm::vec2 &uv = {})
            : Vertex2D(pos), UV(uv) {}
        inline ~Vertex2DTex() = default;
    };

    static_assert(sizeof(Vertex2DTex) == 2 * sizeof(glm::vec2), "Vertex layout error");

    template <>
    class VertexLayout<Vertex2DTex>
    {
    public:
        using VertexType = Vertex2DTex;

        static constexpr inline std::array<VertexAttrib, 2> ATTRIBUTES = {
            VertexAttrib{0, 2, DataType::Float, 0},
            VertexAttrib{1, 2, DataType::Float, sizeof(glm::vec2)},
        };
    };

} // namespace gl_wrapper
