#pragma once

#include "../base/gl_resource.hpp"
#include "../texture/texture_2d.hpp"
#include "renderbuffer.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Framebuffer);

    /// @brief 帧缓冲对象
    class Framebuffer : public GLResource
    {
    private:
        /// @brief 帧缓冲类型
        GLenum m_type = 0;

    public:
        inline Framebuffer() = default;
        inline Framebuffer(GLenum type) { create(type); }
        inline ~Framebuffer() override { destroy(); }

    public:
        Framebuffer &operator=(Framebuffer &&from);
        inline GLenum get_type() const { return m_type; }
        inline base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Framebuffer); }
        inline void bind() const { glBindFramebuffer(m_type, m_id); }
        inline void unbind() const { glBindFramebuffer(m_type, 0); }

    public:
        void create(GLenum type);
        void destroy();

    public:
        inline void set_draw_buffer(GLenum buf) { glDrawBuffer(buf); }
        inline void set_draw_buffers(const std::vector<GLenum> &bufs) { glDrawBuffers(bufs.size(), bufs.data()); }
        inline void set_read_buffer(GLenum src) { glReadBuffer(src); }

        inline void attach_texture(GLenum attachment, const Texture2D &texture, GLint level = 0)
        {
            glFramebufferTexture2D(m_type, attachment, texture.get_type(), texture, level);
        }

        inline void attach_color_texture(const Texture2D &texture, GLsizei index = 0, GLint level = 0)
        {
            attach_texture(GL_COLOR_ATTACHMENT0 + index, texture, level);
        }

        inline void attach_renderbuffer(GLenum attachment, const Renderbuffer &renderbuffer)
        {
            glFramebufferRenderbuffer(m_type, attachment, GL_RENDERBUFFER, renderbuffer);
        }

    public:
        inline void set_parameter(GLenum pname, GLint param) { glFramebufferParameteri(m_type, pname, param); }
        GLint get_parameter(GLenum pname) const;
        inline GLenum check_status() const { return glCheckFramebufferStatus(m_type); }
        inline void read_pixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) const
        {
            glReadPixels(x, y, width, height, format, type, pixels);
        }
        std::vector<base::UInt8> read_pixels_as_RGBA(GLint x, GLint y, GLsizei width, GLsizei height) const;
    };

} // namespace gl_wrapper
