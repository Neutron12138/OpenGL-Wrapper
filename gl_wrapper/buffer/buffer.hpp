#pragma once

#include <array>
#include <vector>
#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Buffer);

    /// @brief 缓冲区对象
    class Buffer : public Resource
    {
    public:
        /// @brief 缓冲区类型
        enum class BufferType : GLenum
        {
            None = GL_NONE,
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
        enum class Usage : GLenum
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

        /// @brief 缓冲区参数名
        enum class ParameterName : GLenum
        {
            Access = GL_BUFFER_ACCESS,
            AccessFlags = GL_BUFFER_ACCESS_FLAGS,
            ImmutableStorage = GL_BUFFER_IMMUTABLE_STORAGE,
            Mapped = GL_BUFFER_MAPPED,
            MapLength = GL_BUFFER_MAP_LENGTH,
            MapOffset = GL_BUFFER_MAP_OFFSET,
            Size = GL_BUFFER_SIZE,
            StorageFlags = GL_BUFFER_STORAGE_FLAGS,
            Usage = GL_BUFFER_USAGE,
        };

        /// @brief 储存标志
        enum class StorageFlag : GLbitfield
        {
            Dynamic = GL_DYNAMIC_STORAGE_BIT,
            MapRead = GL_MAP_READ_BIT,
            MapWrite = GL_MAP_WRITE_BIT,
            MapPersistent = GL_MAP_PERSISTENT_BIT,
            MapCoherent = GL_MAP_COHERENT_BIT,
            Client = GL_CLIENT_STORAGE_BIT,
        };

        static bool is_buffer(GLuint id);

    private:
        /// @brief 缓冲区类型
        BufferType m_type = BufferType::None;

    public:
        Buffer() = default;
        Buffer(Buffer &&from);
        ~Buffer() override;
        BASE_DELETE_COPY_FUNCTION(Buffer);

    public:
        Buffer &operator=(Buffer &&from);
        BufferType get_type() const;
        base::Int64 get_resource_type() const override;

    public:
        void create(BufferType type);
        void destroy();

    public:
        void bind() const;
        void bind_as(BufferType type) const;
        void unbind() const;

    public:
        void set_storage(GLsizeiptr size, const void *data, StorageFlag flags = StorageFlag::Dynamic);
        void set_sub_data(GLintptr offset, GLsizeiptr size, const void *data);
        void clear_data(InternalFormat internalformat, PixelFormat format, GLenum type, const void *data);
        void clear_sub_data(InternalFormat internalformat, GLintptr offset, GLsizeiptr size,
                            PixelFormat format, GLenum type, const void *data);

        template <typename T, std::size_t N>
        inline void set_storage(const std::array<T, N> &data, StorageFlag flags = StorageFlag::Dynamic)
        {
            set_storage(data.size() * sizeof(T), data.data(), flags);
        }

        template <typename T>
        inline void set_storage(const std::vector<T> &data, StorageFlag flags = StorageFlag::Dynamic)
        {
            set_storage(data.size() * sizeof(T), data.data(), flags);
        }

        template <typename T, std::size_t N>
        inline void set_sub_data(GLintptr offset, const std::array<T, N> &data)
        {
            set_sub_data(offset, data.size() * sizeof(T), data.data());
        }

        template <typename T>
        inline void set_sub_data(GLintptr offset, const std::vector<T> &data)
        {
            set_sub_data(offset, data.size() * sizeof(T), data.data());
        }

    public:
        void get_parameter(ParameterName pname, GLint &result) const;
        void get_parameter(ParameterName pname, GLint64 &result) const;
        void *get_pointer() const;
        std::vector<base::UInt8> get_sub_data(GLintptr offset, GLsizeiptr size) const;

        template <typename T>
        T get_parameter(ParameterName pname) const
        {
            T result;
            get_parameter(pname, result);
            return result;
        }

    public:
        void *map(GLenum access = GL_READ_WRITE);
        GLboolean unmap();
        void *map_range(GLintptr offset, GLsizeiptr length, GLbitfield access);
        void flush_mapped_range(GLintptr offset, GLsizeiptr length);

    public:
        void invalidate_data();
        void invalidate_sub_data(GLintptr offset, GLsizeiptr length);
    };

    Buffer::StorageFlag operator|(Buffer::StorageFlag flag1, Buffer::StorageFlag flag2);

} // namespace gl_wrapper
