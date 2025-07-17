#pragma once

#include "renderbuffer.hpp"

namespace gl_wrapper
{
    bool Renderbuffer::is_renderbuffer(GLuint id) { return glIsRenderbuffer(id); }
    void Renderbuffer::unbind() { glBindRenderbuffer(GL_RENDERBUFFER, 0); }

    Renderbuffer::Renderbuffer(Renderbuffer &&from) : Resource(std::move(from)) {}
    Renderbuffer::~Renderbuffer() { destroy(); }

    Renderbuffer &Renderbuffer::operator=(Renderbuffer &&from)
    {
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    base::Int64 Renderbuffer::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Renderbuffer); }
    void Renderbuffer::bind() const { glBindRenderbuffer(GL_RENDERBUFFER, m_id); }

    void Renderbuffer::create()
    {
        destroy();
        glCreateRenderbuffers(1, &m_id);
    }

    void Renderbuffer::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteRenderbuffers(1, &m_id);
        m_id = 0;
    }

    void Renderbuffer::set_storage(GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorage(m_id, internalformat, width, height);
    }

    void Renderbuffer::set_storage_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorageMultisample(m_id, samples, internalformat, width, height);
    }

    GLint Renderbuffer::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetNamedRenderbufferParameteriv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

} // namespace gl_wrapper
