#pragma once

#include <vector>
#include "../base/gl_resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Buffer);

    /// @brief 缓冲区对象
    class Buffer : public GLResource
    {
    public:
        /// @brief 缓冲区类型
        enum class BufferType : GLenum
        {
            Array = GL_ARRAY_BUFFER,
            AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
            CopyRead = GL_COPY_READ_BUFFER,
            CopyWrite = GL_COPY_WRITE_BUFFER,
            DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
            DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
            ElementArray = GL_ELEMENT_ARRAY_BUFFER,
            PixelPack = GL_PIXEL_PACK_BUFFER,
            PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
            Query = GL_QUERY_BUFFER,
            ShaderStorage = GL_SHADER_STORAGE_BUFFER,
            Texture = GL_TEXTURE_BUFFER,
            TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
            Uniform = GL_UNIFORM_BUFFER,
        };

        /// @brief 缓冲区用法
        enum Usage : GLenum
        {
            StreamDraw = GL_STREAM_DRAW,
            StreamRead = GL_STREAM_READ,
            StreamCopy = GL_STREAM_COPY,
            StaticDraw = GL_STATIC_DRAW,
            StaticRead = GL_STATIC_READ,
            StaticCopy = GL_STATIC_COPY,
            DynamicDraw = GL_DYNAMIC_DRAW,
            DynamicRead = GL_DYNAMIC_READ,
            DynamicCopy = GL_DYNAMIC_COPY,
        };

    private:
        /// @brief 缓冲区类型
        BufferType m_type;

    public:
        inline Buffer(BufferType type) : m_type(type) { glGenBuffers(1, &m_id); }
        inline ~Buffer() override { glDeleteBuffers(1, &m_id); }

    public:
        inline void set_type(BufferType type) { m_type = type; }
        inline BufferType get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Buffer); }

    public:
        inline void bind() { glBindBuffer(static_cast<GLenum>(m_type), m_id); }
        inline void unbind() { glBindBuffer(static_cast<GLenum>(m_type), 0); }

        inline void buffer_data(GLsizeiptr size, const void *data, Usage usage = Usage::StaticDraw)
        {
            glBufferData(static_cast<GLenum>(m_type), size, data, static_cast<GLenum>(usage));
        }

        template <typename T>
        inline void buffer_data(const std::vector<T> &vertices, Usage usage = Usage::StaticDraw)
        {
            buffer_data(vertices.size() * sizeof(T), vertices.data(), usage);
        }
    };

} // namespace gl_wrapper
