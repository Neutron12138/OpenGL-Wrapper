#pragma once

#include <glm/glm.hpp>
#include "../base/bindable.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(VertexArray);

    /// @brief 顶点数组对象
    class VertexArray : public Bindable
    {
    public:
        inline VertexArray() { create(); }
        inline VertexArray(VertexArray &&from) : Bindable(std::move(from)) {}
        inline ~VertexArray() override { destroy(); }

    public:
        VertexArray &operator=(VertexArray &&from);
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::VertexArray); }
        inline void bind() const override { glBindVertexArray(m_id); }
        inline void unbind() const override { glBindVertexArray(0); }

    public:
        void create();
        void destroy();

    public:
        inline void enable_vertex_attrib_array(GLuint index) { glEnableVertexAttribArray(index); }
        inline void disable_vertex_attrib_array(GLuint index) { glDisableVertexAttribArray(index); }
        inline void vertex_attrib_divisor(GLuint index, GLuint divisor = 0) { glVertexAttribDivisor(index, divisor); }

        inline void set_vertex_attrib(GLuint index, GLint size, GLenum type, GLboolean normalized,
                                      GLsizei stride, const void *pointer = nullptr)
        {
            glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        }

        inline void set_vertex_attrib(GLuint index, GLint size, GLenum type, GLsizei stride,
                                      const void *pointer = nullptr)
        {
            set_vertex_attrib(index, size, type, GL_FALSE, stride, pointer);
        }

        template <typename T>
        void set_vertex_attrib(GLuint index, base::Size size = sizeof(T), base::Size offset = 0);

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
