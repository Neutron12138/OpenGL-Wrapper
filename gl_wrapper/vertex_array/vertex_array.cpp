#include "vertex_array.hpp"

namespace gl_wrapper
{
    VertexArray &VertexArray::operator=(VertexArray &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    void VertexArray::create()
    {
        destroy();
        glCreateVertexArrays(1, &m_id);
    }

    void VertexArray::destroy()
    {
        glDeleteVertexArrays(1, &m_id);
        m_id = 0;
    }

    template <>
    void VertexArray::set_attrib_format<GLint>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, GL_INT, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<GLuint>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, GL_UNSIGNED_INT, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<GLfloat>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, GL_FLOAT, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec2>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 2, GL_FLOAT, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec3>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 3, GL_FLOAT, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec4>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 4, GL_FLOAT, relativeoffset);
    }

} // namespace gl_wrapper
