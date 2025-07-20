#pragma once

#include "buffer.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(VertexBuffer);

    /// @brief 顶点缓冲区对象
    class VertexBuffer : public Buffer
    {
    public:
        VertexBuffer() = default;
        VertexBuffer(VertexBuffer &&from);
        ~VertexBuffer() override = default;
        BASE_DELETE_COPY_FUNCTION(VertexBuffer);

    public:
        VertexBuffer &operator=(VertexBuffer &&from);
        void create();
    };

    template <typename VertexT, std::size_t N>
    VertexBuffer create_vertex_buffer_from_vertices(
        const std::array<VertexT, N> &vertices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        VertexBuffer vbo;
        vbo.create();
        vbo.set_storage(vertices, flags);

        return vbo;
    }

    template <typename VertexT>
    VertexBuffer create_vertex_buffer_from_vertices(
        const std::vector<VertexT> &vertices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        VertexBuffer vbo;
        vbo.create();
        vbo.set_storage(vertices, flags);

        return vbo;
    }

} // namespace gl_wrapper
