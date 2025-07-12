#include "renderbuffer.hpp"

namespace gl_wrapper
{
    Renderbuffer &Renderbuffer::operator=(Renderbuffer &&from)
    {
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    void Renderbuffer::create()
    {
        destroy();
        glCreateRenderbuffers(1, &m_id);
    }

    void Renderbuffer::destroy()
    {
        glDeleteRenderbuffers(1, &m_id);
        m_id = 0;
    }

    GLint Renderbuffer::get_parameter(GLenum pname) const
    {
        GLint param;
        glGetNamedRenderbufferParameteriv(m_id,pname,&param);
        return param;
    }

} // namespace gl_wrapper
