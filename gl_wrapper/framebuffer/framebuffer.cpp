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
        glGenFramebuffers(1, &m_id);
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
        glGetBufferParameteriv(m_type, pname, &param);
        return param;
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_RGBA(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height * 4);
        read_pixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels.data());
        return pixels;
    }

} // namespace gl_wrapper
