#pragma once

#include "element_buffer.hpp"

namespace gl_wrapper
{
    ElementBuffer::ElementBuffer(ElementBuffer &&from)
        : Buffer(std::move(from)) {}

    ElementBuffer &ElementBuffer::operator=(ElementBuffer &&from)
    {
        Buffer::operator=(std::move(from));
        return *this;
    }

    void ElementBuffer::create() { Buffer::create(BufferType::ElementArray); }

    ElementBuffer create_element_buffer_from_indices(
        const std::vector<GLuint> &indices,
        Buffer::StorageFlag flags)
    {
        ElementBuffer ebo;
        ebo.create();
        ebo.set_storage(indices, flags);

        return std::move(ebo);
    }

} // namespace gl_wrapper
