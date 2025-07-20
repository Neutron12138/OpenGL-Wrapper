#pragma once

#include "framebuffer.hpp"

namespace gl_wrapper
{
    bool Framebuffer::is_framebuffer(GLuint id) { return glIsFramebuffer(id); }

    Framebuffer::Framebuffer(Framebuffer &&from)
        : Resource(std::move(from)),
          m_type(std::exchange(from.m_type, FramebufferType::None)) {}

    Framebuffer::~Framebuffer() { destroy(); }

    Framebuffer &Framebuffer::operator=(Framebuffer &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, FramebufferType::None);
        return *this;
    }

    Framebuffer::FramebufferType Framebuffer::get_type() const { return m_type; }
    base::Int64 Framebuffer::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Framebuffer); }

    void Framebuffer::bind() const { glBindFramebuffer(static_cast<GLenum>(m_type), m_id); }
    void Framebuffer::bind_as(FramebufferType type) const { glBindFramebuffer(static_cast<GLenum>(type), m_id); }
    void Framebuffer::unbind() const { glBindFramebuffer(static_cast<GLenum>(m_type), 0); }

    void Framebuffer::create(FramebufferType type)
    {
        destroy();

        glCreateFramebuffers(1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create Framebuffer object");

        m_type = type;
    }

    void Framebuffer::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteFramebuffers(1, &m_id);
        m_id = 0;
        m_type = FramebufferType::None;
    }

    void Framebuffer::set_draw_buffer(DrawBuffer buf) { glNamedFramebufferDrawBuffer(m_id, static_cast<GLenum>(buf)); }
    void Framebuffer::set_draw_buffers(const std::vector<DrawBuffer> &bufs) { glNamedFramebufferDrawBuffers(m_id, bufs.size(), reinterpret_cast<const GLenum *>(bufs.data())); }
    void Framebuffer::set_read_buffer(ReadBuffer mode) { glNamedFramebufferReadBuffer(m_id, static_cast<GLenum>(mode)); }

    void Framebuffer::attach_texture(Attachment attachment, const Texture2D &texture, GLint level)
    {
        glNamedFramebufferTexture(m_id, static_cast<GLenum>(attachment), texture, level);
    }

    void Framebuffer::attach_color_texture(const Texture2D &texture, GLsizei index, GLint level)
    {
        attach_texture(static_cast<Attachment>(GL_COLOR_ATTACHMENT0 + index), texture, level);
    }

    void Framebuffer::attach_texture_layer(Attachment attachment, const Texture2D &texture, GLint level, GLint layer)
    {
        glNamedFramebufferTextureLayer(m_id, static_cast<GLenum>(attachment), texture, level, layer);
    }

    void Framebuffer::attach_color_texture_layer(const Texture2D &texture, GLsizei index, GLint level, GLint layer)
    {
        attach_texture_layer(static_cast<Attachment>(GL_COLOR_ATTACHMENT0 + index), texture, level, layer);
    }

    void Framebuffer::attach_renderbuffer(Attachment attachment, const Renderbuffer &rbo)
    {
        glNamedFramebufferRenderbuffer(m_id, static_cast<GLenum>(attachment), GL_RENDERBUFFER, rbo);
    }

    void Framebuffer::set_parameter(ParameterName pname, GLint param)
    {
        glNamedFramebufferParameteri(m_id, static_cast<GLenum>(pname), param);
    }

    GLint Framebuffer::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetNamedFramebufferParameteriv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    GLint Framebuffer::get_attachment_parameter(Attachment attachment, GLenum pname) const
    {
        GLint param;
        glGetNamedFramebufferAttachmentParameteriv(m_id, static_cast<GLenum>(attachment), static_cast<GLenum>(pname), &param);
        return param;
    }

    Framebuffer::Status Framebuffer::check_status() const
    {
        return static_cast<Status>(glCheckNamedFramebufferStatus(m_id, static_cast<GLenum>(m_type)));
    }

    void Framebuffer::read_pixels(GLint x, GLint y, GLsizei width, GLsizei height,
                                  PixelFormat format, DataType type, GLsizei buf_size, void *pixels) const
    {
        glReadnPixels(x, y, width, height, static_cast<GLenum>(format), static_cast<GLenum>(type), buf_size, pixels);
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_Red(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height);
        read_pixels(x, y, width, height, PixelFormat::Red, DataType::UnsignedByte, pixels.size(), pixels.data());
        return pixels;
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_RG(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height * 2);
        read_pixels(x, y, width, height, PixelFormat::RG, DataType::UnsignedByte, pixels.size(), pixels.data());
        return pixels;
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_RGB(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height * 3);
        read_pixels(x, y, width, height, PixelFormat::RGB, DataType::UnsignedByte, pixels.size(), pixels.data());
        return pixels;
    }

    std::vector<base::UInt8> Framebuffer::read_pixels_as_RGBA(GLint x, GLint y, GLsizei width, GLsizei height) const
    {
        std::vector<base::UInt8> pixels(width * height * 4);
        read_pixels(x, y, width, height, PixelFormat::RGBA, DataType::UnsignedByte, pixels.size(), pixels.data());
        return pixels;
    }

    Framebuffer create_framebuffer(Framebuffer::FramebufferType type)
    {
        Framebuffer fbo;
        fbo.create(type);

        return fbo;
    }

} // namespace gl_wrapper
