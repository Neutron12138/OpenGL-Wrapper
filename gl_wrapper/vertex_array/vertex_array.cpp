#include "vertex_array.hpp"

namespace gl_wrapper
{
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
