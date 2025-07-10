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
        static inline bool is_buffer(GLuint id) { return glIsBuffer(id); }

    private:
        /// @brief 缓冲区类型
        GLenum m_type = 0;

    public:
        inline Buffer() = default;
        inline Buffer(GLenum type) { create(type); }
        inline Buffer(Buffer &&from) : GLResource(std::move(from)), m_type(std::exchange(from.m_type, 0)) {}
        inline ~Buffer() override { destroy(); }

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

        inline void set_data(GLsizeiptr size, const void *data, GLenum usage = GL_STATIC_DRAW)
        {
            glBufferData(m_type, size, data, usage);
        }

        template <typename T>
        inline void set_data(const std::vector<T> &data, GLenum usage = GL_STATIC_DRAW)
        {
            set_data(data.size() * sizeof(T), data.data(), usage);
        }

        inline void sub_data(GLintptr offset, GLsizeiptr size, const void *data)
        {
            glBufferSubData(m_type, offset, size, data);
        }

        template <typename T>
        inline void sub_data(GLintptr offset, const std::vector<T> &data)
        {
            sub_data(offset, data.size() * sizeof(T), data.data());
        }

    public:
        template <typename T>
        T get_parameter(GLenum pname) const;
        void *get_pointer() const;
        std::vector<base::UInt8> get_sub_data(GLintptr offset, GLsizeiptr size) const;
    };

} // namespace gl_wrapper
