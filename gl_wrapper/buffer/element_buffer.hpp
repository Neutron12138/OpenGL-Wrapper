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

    ElementBuffer create_element_buffer();
    ElementBufferRef create_element_buffer_shared();
    ElementBufferUniqueRef create_element_buffer_unique();

    template <typename VertexT, std::size_t N>
    ElementBuffer create_element_buffer_from_indices(
        const std::array<VertexT, N> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        ElementBuffer ebo;
        ebo.create();
        ebo.set_storage(indices, flags);
        return ebo;
    }

    template <typename VertexT>
    ElementBuffer create_element_buffer_from_indices(
        const std::vector<VertexT> &indices,
        Buffer::StorageFlag flags = Buffer::StorageFlag::Dynamic)
    {
        ElementBuffer ebo;
        ebo.create();
        ebo.set_storage(indices, flags);
        return ebo;
    }

} // namespace gl_wrapper
