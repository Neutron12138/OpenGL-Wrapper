#pragma once

#include <vector>
#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Buffer);

    /// @brief 缓冲区对象
    class Buffer : public Resource
    {
    public:
        static inline bool is_buffer(GLuint id) { return glIsBuffer(id); }

    private:
        /// @brief 缓冲区类型
        GLenum m_type = 0;

    public:
        inline Buffer() = default;
        inline Buffer(GLenum type) { create(type); }
        inline Buffer(Buffer &&from) : Resource(std::move(from)), m_type(std::exchange(from.m_type, 0)) {}
        inline ~Buffer() override { destroy(); }
        BASE_DELETE_COPY_FUNCTION(Buffer);

    public:
        Buffer &operator=(Buffer &&from);
        inline void set_type(GLenum type) { m_type = type; }
        inline GLenum get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Buffer); }

    public:
        void create(GLenum type);
        void destroy();

    public:
        inline void bind() const { glBindBuffer(m_type, m_id); }
        inline void unbind() const { glBindBuffer(m_type, 0); }

    public:
        inline void set_data(GLsizeiptr size, const void *data, GLenum usage = GL_STATIC_DRAW)
        {
            glNamedBufferData(m_id, size, data, usage);
        }

        template <typename T>
        inline void set_data(const std::vector<T> &data, GLenum usage = GL_STATIC_DRAW)
        {
            set_data(data.size() * sizeof(T), data.data(), usage);
        }

        inline void set_storage(GLsizeiptr size, const void *data, GLbitfield flags = 0)
        {
            glNamedBufferStorage(m_id, size, data, flags);
        }

        template <typename T>
        inline void set_storage(const std::vector<T> &data, GLbitfield flags = 0)
        {
            set_storage(data.size() * sizeof(T), data.data(), flags);
        }

        inline void set_sub_data(GLintptr offset, GLsizeiptr size, const void *data)
        {
            glNamedBufferSubData(m_id, offset, size, data);
        }

        template <typename T>
        inline void set_sub_data(GLintptr offset, const std::vector<T> &data)
        {
            set_sub_data(offset, data.size() * sizeof(T), data.data());
        }

    public:
        inline void clear_data(GLenum internalformat, GLenum format, GLenum type, const void *data = nullptr)
        {
            glClearNamedBufferData(m_id, internalformat, format, type, data);
        }

        inline void clear_sub_data(GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
        {
            glClearNamedBufferSubData(m_id, internalformat, offset, size, format, type, data);
        }

    public:
        template <typename T>
        T get_parameter(GLenum pname) const;
        void *get_pointer() const;
        std::vector<base::UInt8> get_sub_data(GLintptr offset, GLsizeiptr size) const;

    public:
        inline void *map(GLenum access = GL_READ_WRITE) { return glMapNamedBuffer(m_id, access); }
        inline GLboolean unmap() { return glUnmapNamedBuffer(m_id); }
        inline void *map_range(GLintptr offset, GLsizeiptr length, GLbitfield access)
        {
            return glMapNamedBufferRange(m_id, offset, length, access);
        }
        inline void flush_mapped_range(GLintptr offset, GLsizeiptr length)
        {
            glFlushMappedNamedBufferRange(m_id, offset, length);
        }

    public:
        inline void invalidate_data() { glInvalidateBufferData(m_id); }
        inline void invalidate_sub_data(GLintptr offset, GLsizeiptr length)
        {
            glInvalidateBufferSubData(m_id, offset, length);
        }
    };

} // namespace gl_wrapper
