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
        destroy();
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    base::Int64 Renderbuffer::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Renderbuffer); }
    void Renderbuffer::bind() const { glBindRenderbuffer(GL_RENDERBUFFER, m_id); }

    void Renderbuffer::create()
    {
        destroy();

        glCreateRenderbuffers(1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_CLASS_RUNTIME_ERROR("Failed to create Renderbuffer object");
    }

    void Renderbuffer::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteRenderbuffers(1, &m_id);
        m_id = 0;
    }

    void Renderbuffer::set_storage(InternalFormat internal_format, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorage(m_id, static_cast<GLenum>(internal_format), width, height);
    }

    void Renderbuffer::set_storage_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
    {
        glNamedRenderbufferStorageMultisample(m_id, samples, internalformat, width, height);
    }

    void Renderbuffer::get_parameter(ParameterName pname, GLint &result) const
    {
        glGetNamedRenderbufferParameteriv(m_id, static_cast<GLenum>(pname), &result);
    }

    GLint Renderbuffer::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetNamedRenderbufferParameteriv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    Renderbuffer create_renderbuffer(InternalFormat internal_format, base::Size width, base::Size height)
    {
        Renderbuffer rbo;
        rbo.create();
        rbo.set_storage(internal_format, width, height);
        return rbo;
    }

    RenderbufferRef create_renderbuffer_shared(InternalFormat internal_format, base::Size width, base::Size height)
    {
        RenderbufferRef rbo = std::make_shared<Renderbuffer>();
        rbo->create();
        rbo->set_storage(internal_format, width, height);
        return rbo;
    }

    RenderbufferUniqueRef create_renderbuffer_unique(InternalFormat internal_format, base::Size width, base::Size height)
    {
        RenderbufferUniqueRef rbo = std::make_unique<Renderbuffer>();
        rbo->create();
        rbo->set_storage(internal_format, width, height);
        return rbo;
    }

} // namespace gl_wrapper
