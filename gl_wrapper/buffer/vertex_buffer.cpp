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

} // namespace gl_wrapper
