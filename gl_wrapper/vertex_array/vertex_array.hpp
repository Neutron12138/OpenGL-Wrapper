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
        inline void bind() { glBindVertexArray(m_id); }

        inline void enable_vertex_attrib_array(GLuint index)
        {
            glEnableVertexAttribArray(index);
        }

        inline void disable_vertex_attrib_array(GLuint index)
        {
            glDisableVertexAttribArray(index);
        }

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
    };

} // namespace gl_wrapper
