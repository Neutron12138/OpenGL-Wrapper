#include "buffer.hpp"

namespace gl_wrapper
{
    template <>
    GLint Buffer::get_parameter(GLenum pname) const
    {
        GLint param;
        glGetBufferParameteriv(m_type, pname, &param);
        return param;
    }

    template <>
    GLint64 Buffer::get_parameter(GLenum pname) const
    {
        GLint64 param;
        glGetBufferParameteri64v(m_type, pname, &param);
        return param;
    }

    void *Buffer::get_pointer() const
    {
        void *param;
        glGetBufferPointerv(m_type, GL_BUFFER_MAP_POINTER, &param);
        return param;
    }

    std::vector<base::UInt8> Buffer::get_sub_data(GLintptr offset, GLsizeiptr size) const
    {
        std::vector<base::UInt8> data(size);
        glGetBufferSubData(m_type, offset, size, data.data());
        return std::move(data);
    }

} // namespace gl_wrapper
