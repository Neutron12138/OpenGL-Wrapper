#include "texture.hpp"

namespace gl_wrapper
{
    Texture &Texture::operator=(Texture &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, 0);
        return *this;
    }

    void Texture::create(GLenum type)
    {
        destroy();
        glCreateTextures(type, 1, &m_id);
        // if(m_id==0)
        m_type = type;
    }

    void Texture::destroy()
    {
        glDeleteTextures(1, &m_id);
        m_id = 0;
        m_type = 0;
    }

    template <>
    void Texture::set_parameter(GLenum pname, GLint param)
    {
        glTextureParameteri(m_id, pname, param);
    }

    template <>
    void Texture::set_parameter(GLenum pname, GLuint param)
    {
        glTextureParameteri(m_id, pname, param);
    }

    template <>
    void Texture::set_parameter(GLenum pname, GLfloat param)
    {
        glTextureParameterf(m_id, pname, param);
    }

    template <>
    GLint Texture::get_parameter(GLenum pname) const
    {
        GLint param;
        glGetTextureParameteriv(m_id, pname, &param);
        return param;
    }

    template <>
    GLfloat Texture::get_parameter(GLenum pname) const
    {
        GLfloat param;
        glGetTextureParameterfv(m_id, pname, &param);
        return param;
    }

    template <>
    GLuint Texture::get_parameter(GLenum pname) const
    {
        GLuint param;
        glGetTextureParameterIuiv(m_id, pname, &param);
        return param;
    }

    void Texture::set_border_color(const glm::vec4 &color)
    {
        glTextureParameterfv(m_id, GL_TEXTURE_BORDER_COLOR, reinterpret_cast<const GLfloat *>(&color));
    }

    glm::vec4 Texture::get_border_color() const
    {
        glm::vec4 color;
        glGetTextureParameterfv(m_id, GL_TEXTURE_BORDER_COLOR, reinterpret_cast<GLfloat *>(&color));
        return color;
    }

} // namespace gl_wrapper
