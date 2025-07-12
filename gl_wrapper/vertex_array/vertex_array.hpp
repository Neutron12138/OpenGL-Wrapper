#pragma once

#include <glm/glm.hpp>
#include "../base/resource.hpp"
#include "../buffer/buffer.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(VertexArray);

    /// @brief 顶点数组对象
    class VertexArray : public Resource
    {
    public:
        static inline bool is_vertex_array(GLuint id) { return glIsVertexArray(id); }
        static inline void unbind() { glBindVertexArray(0); }

    public:
        inline VertexArray() { create(); }
        inline VertexArray(VertexArray &&from) : Resource(std::move(from)) {}
        inline ~VertexArray() override { destroy(); }

    public:
        VertexArray &operator=(VertexArray &&from);
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::VertexArray); }
        inline void bind() const { glBindVertexArray(m_id); }

    public:
        void create();
        void destroy();

    public:
        inline void set_binding_divisor(GLuint index, GLuint divisor = 0) { glVertexArrayBindingDivisor(m_id, index, divisor); }
        inline void enable_attrib(GLuint index) { glEnableVertexArrayAttrib(m_id, index); }
        inline void disable_attrib(GLuint index) { glDisableVertexArrayAttrib(m_id, index); }

        inline void set_attrib_format(GLuint attribindex, GLint size, GLenum type,
                                      GLboolean normalized, GLuint relativeoffset)
        {
            glVertexArrayAttribFormat(m_id, attribindex, size, type, normalized, relativeoffset);
        }

        inline void set_attrib_format(GLuint attribindex, GLint size, GLenum type,
                                      GLuint relativeoffset = 0)
        {
            glVertexArrayAttribFormat(m_id, attribindex, size, type, GL_FALSE, relativeoffset);
        }

        template <typename T>
        void set_attrib_format(GLuint attribindex, GLuint relativeoffset = 0);

        inline void set_attrib_binding(GLuint attribindex, GLuint bindingindex)
        {
            glVertexArrayAttribBinding(m_id, attribindex, bindingindex);
        }

        inline void bind_vertex_buffer(GLuint bindingindex, const Buffer &vbo, GLintptr offset, GLsizei stride)
        {
            glVertexArrayVertexBuffer(m_id, bindingindex, vbo, offset, stride);
        }

        inline void bind_element_buffer(const Buffer &ebo)
        {
            glVertexArrayElementBuffer(m_id, ebo);
        }

    public:
        inline void draw_arrays(GLenum mode, GLint first, GLsizei count) const { glDrawArrays(mode, first, count); }
        inline void draw_arrays(GLenum mode, GLsizei count) const { draw_arrays(mode, 0, count); }

        inline void draw_arrays_instanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) const
        {
            glDrawArraysInstanced(mode, first, count, instancecount);
        }

        inline void draw_arrays_instanced(GLenum mode, GLsizei count, GLsizei instancecount) const
        {
            draw_arrays_instanced(mode, 0, count, instancecount);
        }

        inline void draw_elements(GLenum mode, GLsizei count, GLenum type, const void *indices = nullptr) const
        {
            glDrawElements(mode, count, type, indices);
        }

        inline void draw_elements_instanced(GLenum mode, GLsizei count, GLenum type,
                                            const void *indices, GLsizei instancecount) const
        {
            glDrawElementsInstanced(mode, count, type, indices, instancecount);
        }

        inline void draw_elements_instanced(GLenum mode, GLsizei count, GLenum type,
                                            GLsizei instancecount) const
        {
            glDrawElementsInstanced(mode, count, type, nullptr, instancecount);
        }
    };

} // namespace gl_wrapper
