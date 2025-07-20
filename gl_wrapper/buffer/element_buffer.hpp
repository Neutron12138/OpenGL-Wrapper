#pragma once

#include "buffer.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(ElementBuffer);

    /// @brief 元素缓冲区对象
    class ElementBuffer : public Buffer
    {
    public:
        ElementBuffer() = default;
        ElementBuffer(ElementBuffer &&from);
        ~ElementBuffer() override = default;
        BASE_DELETE_COPY_FUNCTION(ElementBuffer);

    public:
        ElementBuffer &operator=(ElementBuffer &&from);
        void create();
    };

    ElementBuffer create_element_buffer_from_indices(
        const std::vector<GLuint> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic);

    template <std::size_t N>
    ElementBuffer create_element_buffer_from_indices(
        const std::array<GLuint, N> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        ElementBuffer ebo;
        ebo.create();
        ebo.set_storage(indices, flags);

        return std::move(ebo);
    }

} // namespace gl_wrapper
