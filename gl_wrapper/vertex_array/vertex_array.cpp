#include "vertex_array.hpp"

namespace gl_wrapper
{
    bool VertexArray::is_vertex_array(GLuint id) { return glIsVertexArray(id); }
    void VertexArray::unbind() { glBindVertexArray(0); }

    VertexArray::VertexArray(VertexArray &&from) : Resource(std::move(from)) {}
    VertexArray::~VertexArray() { destroy(); }

    VertexArray &VertexArray::operator=(VertexArray &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    base::Int64 VertexArray::get_resource_type() const { return static_cast<base::Int64>(ResourceType::VertexArray); }
    void VertexArray::bind() const { glBindVertexArray(m_id); }

    void VertexArray::create()
    {
        destroy();

        glCreateVertexArrays(1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create VertexArray object");
    }

    void VertexArray::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteVertexArrays(1, &m_id);
        m_id = 0;
    }

    void VertexArray::set_binding_divisor(GLuint index, GLuint divisor) { glVertexArrayBindingDivisor(m_id, index, divisor); }
    void VertexArray::enable_attrib(GLuint index) { glEnableVertexArrayAttrib(m_id, index); }
    void VertexArray::disable_attrib(GLuint index) { glDisableVertexArrayAttrib(m_id, index); }

    void VertexArray::set_attrib_format(GLuint attribindex, GLint size, DataType type,
                                        GLboolean normalized, GLuint relativeoffset)
    {
        glVertexArrayAttribFormat(m_id, attribindex, size, static_cast<GLenum>(type), normalized, relativeoffset);
    }

    void VertexArray::set_attrib_format(GLuint attribindex, GLint size, DataType type,
                                        GLuint relativeoffset)
    {
        glVertexArrayAttribFormat(m_id, attribindex, size, static_cast<GLenum>(type), GL_FALSE, relativeoffset);
    }

    void VertexArray::set_attrib_binding(GLuint attribindex, GLuint bindingindex)
    {
        glVertexArrayAttribBinding(m_id, attribindex, bindingindex);
    }

    void VertexArray::bind_vertex_buffer(GLuint bindingindex, const Buffer &vbo, GLintptr offset, GLsizei stride)
    {
        glVertexArrayVertexBuffer(m_id, bindingindex, vbo, offset, stride);
    }

    void VertexArray::bind_element_buffer(const Buffer &ebo)
    {
        glVertexArrayElementBuffer(m_id, ebo);
    }

    void VertexArray::draw_arrays(DrawMode mode, GLint first, GLsizei count) const
    {
        glDrawArrays(static_cast<GLenum>(mode), first, count);
    }

    void VertexArray::draw_arrays(DrawMode mode, GLsizei count) const { draw_arrays(mode, 0, count); }

    void VertexArray::draw_arrays_instanced(DrawMode mode, GLint first, GLsizei count, GLsizei instancecount) const
    {
        glDrawArraysInstanced(static_cast<GLenum>(mode), first, count, instancecount);
    }

    void VertexArray::draw_arrays_instanced(DrawMode mode, GLsizei count, GLsizei instancecount) const
    {
        draw_arrays_instanced(mode, 0, count, instancecount);
    }

    void VertexArray::draw_elements(DrawMode mode, GLsizei count, DataType type, const void *indices) const
    {
        glDrawElements(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), indices);
    }

    void VertexArray::draw_elements_instanced(DrawMode mode, GLsizei count, DataType type,
                                              const void *indices, GLsizei instancecount) const
    {
        glDrawElementsInstanced(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), indices, instancecount);
    }

    void VertexArray::draw_elements_instanced(DrawMode mode, GLsizei count, DataType type,
                                              GLsizei instancecount) const
    {
        glDrawElementsInstanced(static_cast<GLenum>(mode), count, static_cast<GLenum>(type), nullptr, instancecount);
    }

} // namespace gl_wrapper
