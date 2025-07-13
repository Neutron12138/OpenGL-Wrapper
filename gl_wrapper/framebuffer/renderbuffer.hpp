#pragma once

#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Renderbuffer);

    /// @brief 渲染缓冲对象
    class Renderbuffer : public Resource
    {
    public:
        static inline bool is_renderbuffer(GLuint id) { return glIsRenderbuffer(id); }
        static inline void unbind() { glBindRenderbuffer(GL_RENDERBUFFER, 0); }

    public:
        inline Renderbuffer() { create(); }
        inline Renderbuffer(Renderbuffer &&from) : Resource(std::move(from)) {}
        inline ~Renderbuffer() override { destroy(); }
        BASE_DELETE_COPY_FUNCTION(Renderbuffer);

    public:
        Renderbuffer &operator=(Renderbuffer &&from);
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Renderbuffer); }
        inline void bind() const { glBindRenderbuffer(GL_RENDERBUFFER, m_id); }

    public:
        void create();
        void destroy();

    public:
        inline void set_storage(GLenum internalformat, GLsizei width, GLsizei height)
        {
            glNamedRenderbufferStorage(m_id, internalformat, width, height);
        }

        inline void set_storage_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
        {
            glNamedRenderbufferStorageMultisample(m_id, samples, internalformat, width, height);
        }

    public:
        GLint get_parameter(GLenum pname) const;
    };

} // namespace gl_wrapper
