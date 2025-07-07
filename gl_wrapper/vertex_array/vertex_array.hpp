#pragma once

#include <glm/glm.hpp>
#include "../base/gl_resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(VertexArray);

    /// @brief 顶点数组对象
    class VertexArray : public GLResource
    {
    public:
        static inline void unbind() { glBindVertexArray(0); }

    public:
        inline VertexArray() { glGenVertexArrays(1, &m_id); }
        inline ~VertexArray() override { glDeleteVertexArrays(1, &m_id); }

    public:
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::VertexArray); }

    public:
        inline void bind() const { glBindVertexArray(m_id); }
        inline void enable_vertex_attrib_array(GLuint index) { glEnableVertexAttribArray(index); }
        inline void disable_vertex_attrib_array(GLuint index) { glDisableVertexAttribArray(index); }
        inline void vertex_attrib_divisor(GLuint index, GLuint divisor = 0) { glVertexAttribDivisor(index, divisor); }

        inline void vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized,
                                          GLsizei stride, const void *pointer = nullptr)
        {
            glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        }

        inline void vertex_attrib_pointer(GLuint index, GLint size, GLenum type, GLsizei stride,
                                          const void *pointer = nullptr)
        {
            vertex_attrib_pointer(index, size, type, GL_FALSE, stride, pointer);
        }

        template <typename T>
        void vertex_attrib_pointer(GLuint index, base::Size size = sizeof(T), base::Size offset = 0);

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
