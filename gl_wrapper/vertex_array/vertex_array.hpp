#pragma once

#include <glm/glm.hpp>
#include "../base/resource.hpp"
#include "../buffer/vertex_buffer.hpp"
#include "../buffer/element_buffer.hpp"
#include "../vertex/vertex_layout.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(VertexArray);

    /// @brief 顶点数组对象
    class VertexArray : public Resource
    {
    public:
        /// @brief 绘制模式
        enum class DrawMode : GLenum
        {
            Points = GL_POINTS,
            LineStrip = GL_LINE_STRIP,
            LineLoop = GL_LINE_LOOP,
            Lines = GL_LINES,
            LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
            LinesAdjacency = GL_LINES_ADJACENCY,
            TriangleStrip = GL_TRIANGLE_STRIP,
            TriangleFan = GL_TRIANGLE_FAN,
            Triangles = GL_TRIANGLES,
            TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
            TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
            Patches = GL_PATCHES,
        };

        static bool is_vertex_array(GLuint id);
        static void unbind();

    public:
        VertexArray() = default;
        VertexArray(VertexArray &&from);
        ~VertexArray() override;
        BASE_DELETE_COPY_FUNCTION(VertexArray);

    public:
        VertexArray &operator=(VertexArray &&from);
        base::Int64 get_resource_type() const override;
        void bind() const;

    public:
        void create();
        void destroy();

    public:
        void set_binding_divisor(GLuint index, GLuint divisor = 0);
        void enable_attrib(GLuint index);
        void disable_attrib(GLuint index);
        void set_attrib_format(GLuint attribindex, GLint size, DataType type,
                               GLboolean normalized, GLuint relativeoffset);
        void set_attrib_format(GLuint attribindex, GLint size, DataType type,
                               GLuint relativeoffset = 0);
        void set_attrib_binding(GLuint attribindex, GLuint bindingindex);
        void bind_vertex_buffer(GLuint bindingindex, const VertexBuffer &vbo, GLintptr offset, GLsizei stride);
        void bind_element_buffer(const ElementBuffer &ebo);

        template <typename T>
        void set_attrib_format(GLuint attribindex, GLuint relativeoffset = 0);

    public:
        void draw_arrays(DrawMode mode, GLint first, GLsizei count) const;
        void draw_arrays(DrawMode mode, GLsizei count) const;
        void draw_arrays_instanced(DrawMode mode, GLint first, GLsizei count, GLsizei instancecount) const;
        void draw_arrays_instanced(DrawMode mode, GLsizei count, GLsizei instancecount) const;
        void draw_elements(DrawMode mode, GLsizei count, DataType type, const void *indices = nullptr) const;
        void draw_elements_instanced(DrawMode mode, GLsizei count, DataType type,
                                     const void *indices, GLsizei instancecount) const;
        void draw_elements_instanced(DrawMode mode, GLsizei count, DataType type,
                                     GLsizei instancecount) const;
    };

    VertexArray create_vertex_array();
    VertexArrayRef create_vertex_array_shared();
    VertexArrayUniqueRef create_vertex_array_unique();

} // namespace gl_wrapper
