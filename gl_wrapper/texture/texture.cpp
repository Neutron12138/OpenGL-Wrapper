#pragma once

#include "texture.hpp"

namespace gl_wrapper
{
    bool Texture::is_texture(GLuint id) { return glIsTexture(id); }

    Texture::Texture(Texture &&from)
        : Resource(std::move(from)),
          m_type(std::exchange(from.m_type, TextureType::None)),
          m_width(std::exchange(from.m_width, 0)),
          m_height(std::exchange(from.m_height, 0)),
          m_depth(std::exchange(from.m_depth, 0)),
          m_internal_format(std::exchange(from.m_internal_format, InternalFormat::None)) {}

    Texture::~Texture() { destroy(); }

    Texture &Texture::operator=(Texture &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, TextureType::None);
        m_width = std::exchange(from.m_width, 0);
        m_height = std::exchange(from.m_height, 0);
        m_depth = std::exchange(from.m_depth, 0);
        m_internal_format = std::exchange(from.m_internal_format, InternalFormat::None);

        return *this;
    }

    Texture::TextureType Texture::get_type() const { return m_type; }
    base::Int64 Texture::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Texture); }
    void Texture::bind() const { glBindTexture(static_cast<GLenum>(m_type), m_id); }
    void Texture::unbind() const { glBindTexture(static_cast<GLenum>(m_type), 0); }
    void Texture::bind_unit(GLuint unit) const { glBindTextureUnit(unit, m_id); }

    base::Size Texture::get_width() const { return m_width; }
    base::Size Texture::get_height() const { return m_height; }
    base::Size Texture::get_depth() const { return m_depth; }
    InternalFormat Texture::get_internal_format() const { return m_internal_format; }

    void Texture::create(TextureType type)
    {
        destroy();

        glCreateTextures(static_cast<GLenum>(type), 1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to create Texture object, type: ", static_cast<GLenum>(type));

        m_type = type;
    }

    void Texture::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteTextures(1, &m_id);
        m_id = 0;
        m_type = TextureType::None;
    }

    void Texture::generate_mipmap() { glGenerateTextureMipmap(m_id); }
    void Texture::set_wrap_s(WrapParameter wrap) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, static_cast<GLint>(wrap)); }
    void Texture::set_wrap_t(WrapParameter wrap) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, static_cast<GLint>(wrap)); }
    void Texture::set_wrap_r(WrapParameter wrap) { glTextureParameteri(m_id, GL_TEXTURE_WRAP_R, static_cast<GLint>(wrap)); }
    void Texture::set_min_filter(MinFilter filter) { glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(filter)); }
    void Texture::set_mag_filter(MagFilter filter) { glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(filter)); }

    template <>
    void Texture::set_parameter(ParameterName pname, GLint param)
    {
        glTextureParameteri(m_id, static_cast<GLenum>(pname), param);
    }

    template <>
    void Texture::set_parameter(ParameterName pname, GLuint param)
    {
        glTextureParameteri(m_id, static_cast<GLenum>(pname), param);
    }

    template <>
    void Texture::set_parameter(ParameterName pname, GLfloat param)
    {
        glTextureParameterf(m_id, static_cast<GLenum>(pname), param);
    }

    template <>
    GLint Texture::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetTextureParameteriv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    template <>
    GLfloat Texture::get_parameter(ParameterName pname) const
    {
        GLfloat param;
        glGetTextureParameterfv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    template <>
    GLuint Texture::get_parameter(ParameterName pname) const
    {
        GLuint param;
        glGetTextureParameterIuiv(m_id, static_cast<GLenum>(pname), &param);
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
