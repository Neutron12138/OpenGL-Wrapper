#include "vertex_array.hpp"

namespace gl_wrapper
{
    template <>
    void VertexArray::vertex_attrib_pointer<GLint>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 1, GL_INT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<GLuint>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 1, GL_UNSIGNED_INT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<GLfloat>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 1, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<glm::vec1>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 1, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<glm::vec2>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 2, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<glm::vec3>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 3, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

    template <>
    void VertexArray::vertex_attrib_pointer<glm::vec4>(GLuint index, base::Size size, base::Size offset)
    {
        vertex_attrib_pointer(index, 4, GL_FLOAT, size, reinterpret_cast<const void *>(offset));
    }

} // namespace gl_wrapper
