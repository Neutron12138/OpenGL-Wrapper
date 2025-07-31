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

    ElementBuffer create_element_buffer_from_indices()
    {
        ElementBuffer ebo;
        ebo.create();
        return ebo;
    }

    ElementBufferRef create_element_buffer_shared_from_indices()
    {
        ElementBufferRef ebo = std::make_shared<ElementBuffer>();
        ebo->create();
        return ebo;
    }

    ElementBufferUniqueRef create_element_buffer_unique_from_indices()
    {
        ElementBufferUniqueRef ebo = std::make_unique<ElementBuffer>();
        ebo->create();
        return ebo;
    }

} // namespace gl_wrapper
