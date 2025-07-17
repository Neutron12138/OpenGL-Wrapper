#pragma once

#include "../base/resource.hpp"
#include "../texture/texture_2d.hpp"
#include "renderbuffer.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Framebuffer);

    /// @brief 帧缓冲对象
    class Framebuffer : public Resource
    {
    public:
        /// @brief 帧缓冲类型
        enum FramebufferType : GLenum
        {
            None = GL_NONE,
            Draw = GL_DRAW_FRAMEBUFFER,
            Read = GL_READ_FRAMEBUFFER,
            Default = GL_FRAMEBUFFER,
        };

        /// @brief 绘制缓冲
        enum class DrawBuffer : GLenum
        {
            None = GL_NONE,
            FrontLeft = GL_FRONT_LEFT,
            FrontRight = GL_FRONT_RIGHT,
            BackLeft = GL_BACK_LEFT,
            BackRight = GL_BACK_RIGHT,
            Front = GL_FRONT,
            Back = GL_BACK,
            Left = GL_LEFT,
            Right = GL_RIGHT,
            FrontAndBack = GL_FRONT_AND_BACK,
        };

        /// @brief 读取缓冲
        enum class ReadBuffer : GLenum
        {
            FrontLeft = GL_FRONT_LEFT,
            FrontRight = GL_FRONT_RIGHT,
            BackLeft = GL_BACK_LEFT,
            BackRight = GL_BACK_RIGHT,
            Front = GL_FRONT,
            Back = GL_BACK,
            Left = GL_LEFT,
            Right = GL_RIGHT,
            Color0 = GL_COLOR_ATTACHMENT0,
            Color1 = GL_COLOR_ATTACHMENT1,
            Color2 = GL_COLOR_ATTACHMENT2,
            Color3 = GL_COLOR_ATTACHMENT3,
            Color4 = GL_COLOR_ATTACHMENT4,
            Color5 = GL_COLOR_ATTACHMENT5,
            Color6 = GL_COLOR_ATTACHMENT6,
            Color7 = GL_COLOR_ATTACHMENT7,
            Color8 = GL_COLOR_ATTACHMENT8,
            Color9 = GL_COLOR_ATTACHMENT9,
            Color10 = GL_COLOR_ATTACHMENT10,
            Color11 = GL_COLOR_ATTACHMENT11,
            Color12 = GL_COLOR_ATTACHMENT12,
            Color13 = GL_COLOR_ATTACHMENT13,
            Color14 = GL_COLOR_ATTACHMENT14,
            Color15 = GL_COLOR_ATTACHMENT15,
            Color16 = GL_COLOR_ATTACHMENT16,
            Color17 = GL_COLOR_ATTACHMENT17,
            Color18 = GL_COLOR_ATTACHMENT18,
            Color19 = GL_COLOR_ATTACHMENT19,
            Color20 = GL_COLOR_ATTACHMENT20,
            Color21 = GL_COLOR_ATTACHMENT21,
            Color22 = GL_COLOR_ATTACHMENT22,
            Color23 = GL_COLOR_ATTACHMENT23,
            Color24 = GL_COLOR_ATTACHMENT24,
            Color25 = GL_COLOR_ATTACHMENT25,
            Color26 = GL_COLOR_ATTACHMENT26,
            Color27 = GL_COLOR_ATTACHMENT27,
            Color28 = GL_COLOR_ATTACHMENT28,
            Color29 = GL_COLOR_ATTACHMENT29,
            Color30 = GL_COLOR_ATTACHMENT30,
            Color31 = GL_COLOR_ATTACHMENT31,
        };

        /// @brief  帧缓冲参数名
        enum class ParameterName : GLenum
        {
            DefaultWidth = GL_FRAMEBUFFER_DEFAULT_WIDTH,
            DefaultHeight = GL_FRAMEBUFFER_DEFAULT_HEIGHT,
            DefaultLayers = GL_FRAMEBUFFER_DEFAULT_LAYERS,
            DefaultSamples = GL_FRAMEBUFFER_DEFAULT_SAMPLES,
            DefaultFixedSampleLocations = GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS,
            Doublebuffer = GL_DOUBLEBUFFER,
            ImplementationColorReadFormat = GL_IMPLEMENTATION_COLOR_READ_FORMAT,
            ImplementationColorReadType = GL_IMPLEMENTATION_COLOR_READ_TYPE,
            Samples = GL_SAMPLES,
            SampleBuffers = GL_SAMPLE_BUFFERS,
            Stereo = GL_STEREO,
        };

        /// @brief 帧缓冲附件
        enum class Attachment : GLenum
        {
            Color0 = GL_COLOR_ATTACHMENT0,
            Color1 = GL_COLOR_ATTACHMENT1,
            Color2 = GL_COLOR_ATTACHMENT2,
            Color3 = GL_COLOR_ATTACHMENT3,
            Color4 = GL_COLOR_ATTACHMENT4,
            Color5 = GL_COLOR_ATTACHMENT5,
            Color6 = GL_COLOR_ATTACHMENT6,
            Color7 = GL_COLOR_ATTACHMENT7,
            Color8 = GL_COLOR_ATTACHMENT8,
            Color9 = GL_COLOR_ATTACHMENT9,
            Color10 = GL_COLOR_ATTACHMENT10,
            Color11 = GL_COLOR_ATTACHMENT11,
            Color12 = GL_COLOR_ATTACHMENT12,
            Color13 = GL_COLOR_ATTACHMENT13,
            Color14 = GL_COLOR_ATTACHMENT14,
            Color15 = GL_COLOR_ATTACHMENT15,
            Color16 = GL_COLOR_ATTACHMENT16,
            Color17 = GL_COLOR_ATTACHMENT17,
            Color18 = GL_COLOR_ATTACHMENT18,
            Color19 = GL_COLOR_ATTACHMENT19,
            Color20 = GL_COLOR_ATTACHMENT20,
            Color21 = GL_COLOR_ATTACHMENT21,
            Color22 = GL_COLOR_ATTACHMENT22,
            Color23 = GL_COLOR_ATTACHMENT23,
            Color24 = GL_COLOR_ATTACHMENT24,
            Color25 = GL_COLOR_ATTACHMENT25,
            Color26 = GL_COLOR_ATTACHMENT26,
            Color27 = GL_COLOR_ATTACHMENT27,
            Color28 = GL_COLOR_ATTACHMENT28,
            Color29 = GL_COLOR_ATTACHMENT29,
            Color30 = GL_COLOR_ATTACHMENT30,
            Color31 = GL_COLOR_ATTACHMENT31,
            Depth = GL_DEPTH_ATTACHMENT,
            Stencil = GL_STENCIL_ATTACHMENT,
            DepthStencil = GL_DEPTH_STENCIL_ATTACHMENT,
        };

        /// @brief 帧缓冲状态
        enum class Status : GLenum
        {
            Complete = GL_FRAMEBUFFER_COMPLETE,
            Undefined = GL_FRAMEBUFFER_UNDEFINED,
            IncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
            IncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
            IncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
            IncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
            Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
            IncompleteMultisample = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,
            IncompleteLayerTargets = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,
        };

        static bool is_framebuffer(GLuint id);

    private:
        /// @brief 帧缓冲类型
        FramebufferType m_type = FramebufferType::None;

    public:
        Framebuffer() = default;
        Framebuffer(FramebufferType type);
        ~Framebuffer() override;
        BASE_DELETE_COPY_FUNCTION(Framebuffer);

    public:
        Framebuffer &operator=(Framebuffer &&from);
        void set_type(FramebufferType type);
        FramebufferType get_type() const;
        base::Int64 get_resource_type() const override;
        void bind() const;
        void unbind() const;

    public:
        void create(FramebufferType type);
        void destroy();

    public:
        void set_draw_buffer(DrawBuffer buf);
        void set_draw_buffers(const std::vector<DrawBuffer> &bufs);
        void set_read_buffer(ReadBuffer mode);

    public:
        void attach_texture(Attachment attachment, const Texture2D &texture, GLint level = 0);
        void attach_color_texture(const Texture2D &texture, GLsizei index = 0, GLint level = 0);
        void attach_texture_layer(Attachment attachment, const Texture2D &texture, GLint level = 0, GLint layer = 0);
        void attach_color_texture_layer(const Texture2D &texture, GLsizei index = 0, GLint level = 0, GLint layer = 0);
        void attach_renderbuffer(Attachment attachment, const Renderbuffer &rbo);

    public:
        void set_parameter(ParameterName pname, GLint param);
        GLint get_parameter(ParameterName pname) const;
        GLint get_attachment_parameter(Attachment attachment, GLenum pname) const;
        Status check_status() const;
        void read_pixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) const
        {
            glReadPixels(x, y, width, height, format, type, pixels);
        }
        std::vector<base::UInt8> read_pixels_as_RGBA(GLint x, GLint y, GLsizei width, GLsizei height) const;
    };

} // namespace gl_wrapper
