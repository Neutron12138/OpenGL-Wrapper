#pragma once

#include "buffer.hpp"

namespace gl_wrapper
{
    bool Buffer::is_buffer(GLuint id) { return glIsBuffer(id); }

    Buffer::Buffer(BufferType type) { create(type); }
    Buffer::Buffer(Buffer &&from) : Resource(std::move(from)),
                                    m_type(std::exchange(from.m_type, BufferType::None)) {}
    Buffer::~Buffer() { destroy(); }

    Buffer &Buffer::operator=(Buffer &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, BufferType::None);
        return *this;
    }

    void Buffer::set_type(BufferType type) { m_type = type; }
    Buffer::BufferType Buffer::get_type() const { return m_type; }
    base::Int64 Buffer::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Buffer); }

    void Buffer::create(BufferType type)
    {
        destroy();

        glCreateBuffers(1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create Buffer object");

        m_type = type;
    }

    void Buffer::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteBuffers(1, &m_id);
        m_id = 0;
        m_type = BufferType::None;
    }

    void Buffer::bind() const { glBindBuffer(static_cast<GLenum>(m_type), m_id); }
    void Buffer::unbind() const { glBindBuffer(static_cast<GLenum>(m_type), 0); }

    void Buffer::set_data(GLsizeiptr size, const void *data, Usage usage)
    {
        glNamedBufferData(m_id, size, data, static_cast<GLenum>(usage));
    }

    void Buffer::set_storage(GLsizeiptr size, const void *data, StorageFlag flags)
    {
        glNamedBufferStorage(m_id, size, data, static_cast<GLenum>(flags));
    }

    void Buffer::set_sub_data(GLintptr offset, GLsizeiptr size, const void *data)
    {
        glNamedBufferSubData(m_id, offset, size, data);
    }

    void Buffer::clear_data(InternalFormat internalformat, BaseFormat format, GLenum type, const void *data)
    {
        glClearNamedBufferData(m_id, static_cast<GLenum>(internalformat), static_cast<GLenum>(format), type, data);
    }

    void Buffer::clear_sub_data(InternalFormat internalformat, GLintptr offset, GLsizeiptr size,
                                BaseFormat format, GLenum type, const void *data)
    {
        glClearNamedBufferSubData(m_id, static_cast<GLenum>(internalformat), offset,
                                  size, static_cast<GLenum>(format), type, data);
    }

    template <>
    GLint Buffer::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetNamedBufferParameteriv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    template <>
    GLint64 Buffer::get_parameter(ParameterName pname) const
    {
        GLint64 param;
        glGetNamedBufferParameteri64v(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    void *Buffer::get_pointer() const
    {
        void *param;
        glGetNamedBufferPointerv(m_id, GL_BUFFER_MAP_POINTER, &param);
        return param;
    }

    std::vector<base::UInt8> Buffer::get_sub_data(GLintptr offset, GLsizeiptr size) const
    {
        std::vector<base::UInt8> data(size);
        glGetNamedBufferSubData(m_id, offset, size, data.data());
        return std::move(data);
    }

    void *Buffer::map(GLenum access) { return glMapNamedBuffer(m_id, access); }
    GLboolean Buffer::unmap() { return glUnmapNamedBuffer(m_id); }

    void *Buffer::map_range(GLintptr offset, GLsizeiptr length, GLbitfield access)
    {
        return glMapNamedBufferRange(m_id, offset, length, access);
    }

    void Buffer::flush_mapped_range(GLintptr offset, GLsizeiptr length)
    {
        glFlushMappedNamedBufferRange(m_id, offset, length);
    }

    void Buffer::invalidate_data() { glInvalidateBufferData(m_id); }
    void Buffer::invalidate_sub_data(GLintptr offset, GLsizeiptr length)
    {
        glInvalidateBufferSubData(m_id, offset, length);
    }

    Buffer::StorageFlag operator|(Buffer::StorageFlag flag1, Buffer::StorageFlag flag2)
    {
        return static_cast<Buffer::StorageFlag>(
            static_cast<GLbitfield>(flag1) | static_cast<GLbitfield>(flag2));
    }

} // namespace gl_wrapper
