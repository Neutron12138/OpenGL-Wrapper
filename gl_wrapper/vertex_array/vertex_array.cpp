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
        glGenVertexArrays(1, &m_id);
    }

    void VertexArray::destroy()
    {
        glDeleteVertexArrays(1, &m_id);
        m_id = 0;
    }

    template <>
    void VertexArray::set_vertex_attrib<GLint>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 1, GL_INT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<GLuint>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 1, GL_UNSIGNED_INT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<GLfloat>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 1, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<glm::vec1>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 1, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<glm::vec2>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 2, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<glm::vec3>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 3, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::set_vertex_attrib<glm::vec4>(GLuint index, base::Size size, base::Size offset)
    {
        set_vertex_attrib(index, 4, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

} // namespace gl_wrapper
