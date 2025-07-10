#pragma once

#include "../base/bindable.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Renderbuffer);

    /// @brief 渲染缓冲对象
    class Renderbuffer : public Bindable
    {
    public:
        inline Renderbuffer() { create(); }
        inline Renderbuffer(Renderbuffer &&from) : Bindable(std::move(from)) {}
        inline ~Renderbuffer() override { destroy(); }

    public:
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Renderbuffer); }
        inline void bind() const override { glBindRenderbuffer(GL_RENDERBUFFER, m_id); }
        inline void unbind() const override { glBindRenderbuffer(GL_RENDERBUFFER, 0); }

    public:
        void create();
        void destroy();

    public:
        inline void set_storage(GLenum internalformat, GLsizei width, GLsizei height)
        {
            glRenderbufferStorage(GL_RENDERBUFFER, internalformat, width, height);
        }

        inline void set_storage_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
        {
            glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat, width, height);
        }

    public:
        GLint get_parameter(GLenum pname) const;
    };

} // namespace gl_wrapper
