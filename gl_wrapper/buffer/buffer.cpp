#include "buffer.hpp"

namespace gl_wrapper
{
    Buffer &Buffer::operator=(Buffer &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, 0);
        return *this;
    }

    void Buffer::create(GLenum type)
    {
        destroy();
        glCreateBuffers(1, &m_id);
        m_type = type;
    }

    void Buffer::destroy()
    {
        glDeleteBuffers(1, &m_id);
        m_id = 0;
        m_type = 0;
    }

    template <>
    GLint Buffer::get_parameter(GLenum pname) const
    {
        GLint param;
        glGetNamedBufferParameteriv(m_id, pname, &param);
        return param;
    }

    template <>
    GLint64 Buffer::get_parameter(GLenum pname) const
    {
        GLint64 param;
        glGetNamedBufferParameteri64v(m_id, pname, &param);
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

} // namespace gl_wrapper
