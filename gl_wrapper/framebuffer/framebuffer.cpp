#include "framebuffer.hpp"

namespace gl_wrapper
{
    Framebuffer &Framebuffer::operator=(Framebuffer &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, 0);
        return *this;
    }

    void Framebuffer::create(GLenum type)
    {
        destroy();
        glCreateFramebuffers(1, &m_id);
        m_type = type;
    }

    void Framebuffer::destroy()
    {
        glDeleteFramebuffers(1, &m_id);
        m_id = 0;
        m_type = 0;
    }

    GLint Framebuffer::get_parameter(GLenum pname) const
    {
        GLint param;
        glGetNamedFramebufferParameteriv(m_id, pname, &param);
        return param;
    }

    GLint Framebuffer::get_attachment_parameter(GLenum attachment, GLenum pname) const
    {
        GLint param;
        glGetNamedFramebufferAttachmentParameteriv(m_id, attachment, pname, &param);
        return param;
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_RGBA(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height * 4);
        read_pixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
        return pixels;
    }

} // namespace gl_wrapper
