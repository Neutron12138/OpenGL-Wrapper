#pragma once

#include "vertex_buffer.hpp"

namespace gl_wrapper
{
    VertexBuffer::VertexBuffer(VertexBuffer &&from)
        : Buffer(std::move(from)) {}

    VertexBuffer &VertexBuffer::operator=(VertexBuffer &&from)
    {
        Buffer::operator=(std::move(from));
        return *this;
    }

    void VertexBuffer::create() { Buffer::create(BufferType::Array); }

    VertexBuffer create_vertex_buffer()
    {
        VertexBuffer buffer;
        buffer.create();
        return buffer;
    }

    VertexBufferRef create_vertex_buffer_shared()
    {
        VertexBufferRef buffer = std::make_shared<VertexBuffer>();
        buffer->create();
        return buffer;
    }

    VertexBufferUniqueRef create_vertex_buffer_unique()
    {
        VertexBufferUniqueRef buffer = std::make_unique<VertexBuffer>();
        buffer->create();
        return buffer;
    }

} // namespace gl_wrapper
