#pragma once

#include "vertex_array.hpp"

namespace gl_wrapper
{
    template <>
    void VertexArray::set_attrib_format<GLint>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, DataType::Int, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<GLuint>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, DataType::UnsignedInt, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<GLfloat>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 1, DataType::Float, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec2>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 2, DataType::Float, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec3>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 3, DataType::Float, relativeoffset);
    }

    template <>
    void VertexArray::set_attrib_format<glm::vec4>(GLuint attribindex, GLuint relativeoffset)
    {
        set_attrib_format(attribindex, 4, DataType::Float, relativeoffset);
    }

} // namespace gl_wrapper
