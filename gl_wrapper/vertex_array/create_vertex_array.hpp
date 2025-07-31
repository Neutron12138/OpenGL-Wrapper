#pragma once

#include "vertex_array.hpp"

namespace gl_wrapper
{
    // VAO设置顶点属性

    template <typename VL>
    void vertex_array_set_vertex_attrib(VertexArray &vao)
    {
        for (const auto &attrib : VL::ATTRIBUTES)
        {
            vao.enable_attrib(attrib.attrib_index);
            vao.set_attrib_binding(attrib.attrib_index, 0);
            vao.set_attrib_format(attrib.attrib_index, attrib.vertex_size, attrib.data_type, attrib.relative_offset);
        }
    }

    // 从缓冲区创建VAO

    template <typename VertexT>
    VertexArray create_vertex_array_from_buffers(const VertexBuffer &vbo)
    {
        VertexArray vao = create_vertex_array();
        vao.bind_vertex_buffer(0, vbo, 0, sizeof(VertexT));
        vertex_array_set_vertex_attrib<VertexLayout<VertexT>>(vao);
        return vao;
    }

    template <typename VertexT>
    VertexArray create_vertex_array_from_buffers(const VertexBuffer &vbo, const ElementBuffer &ebo)
    {
        VertexArray vao = create_vertex_array();
        vao.bind_vertex_buffer(0, vbo, 0, sizeof(VertexT));
        vao.bind_element_buffer(ebo);
        vertex_array_set_vertex_attrib<VertexLayout<VertexT>>(vao);
        return vao;
    }

    // 通过顶点创建VAO

    template <typename VertexT, std::size_t N>
    VertexArray create_vertex_array_from_vertices(
        const std::array<VertexT, N> &vertices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags));
    }

    template <typename VertexT>
    VertexArray create_vertex_array_from_vertices(
        const std::vector<VertexT> &vertices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags));
    }

    // 通过顶点与顶点索引创建VAO

    template <typename VertexT, std::size_t N1, std::size_t N2>
    VertexArray create_vertex_array_from_vertices(
        const std::array<VertexT, N1> &vertices,
        const std::array<GLuint, N2> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags),
            create_element_buffer_from_indices(indices, flags));
    }

    template <typename VertexT, std::size_t N>
    VertexArray create_vertex_array_from_vertices(
        const std::vector<VertexT> &vertices,
        const std::array<GLuint, N> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags),
            create_element_buffer_from_indices(indices, flags));
    }

    template <typename VertexT, std::size_t N>
    VertexArray create_vertex_array_from_vertices(
        const std::array<VertexT, N> &vertices,
        const std::vector<GLuint> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags),
            create_element_buffer_from_indices(indices, flags));
    }

    template <typename VertexT>
    VertexArray create_vertex_array_from_vertices(
        const std::vector<VertexT> &vertices,
        const std::vector<GLuint> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        return create_vertex_array_from_buffers<VertexT>(
            create_vertex_buffer_from_vertices(vertices, flags),
            create_element_buffer_from_indices(indices, flags));
    }

} // namespace gl_wrapper
