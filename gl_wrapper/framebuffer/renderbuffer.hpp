#pragma once

#include "../base/resource.hpp"

namespace gl_wrapper
{
    BASE_DECLARE_REF_TYPE(Renderbuffer);

    /// @brief 渲染缓冲对象
    class Renderbuffer : public Resource
    {
    public:
        /// @brief 渲染缓冲参数名
        enum class ParameterName : GLenum
        {
            Width = GL_RENDERBUFFER_WIDTH,
            Height = GL_RENDERBUFFER_HEIGHT,
            InternalFormat = GL_RENDERBUFFER_INTERNAL_FORMAT,
            Samples = GL_RENDERBUFFER_SAMPLES,

            RedSize = GL_RENDERBUFFER_RED_SIZE,
            GreenSize = GL_RENDERBUFFER_GREEN_SIZE,
            BluseSize = GL_RENDERBUFFER_BLUE_SIZE,
            AlphaSize = GL_RENDERBUFFER_ALPHA_SIZE,
            DepthSize = GL_RENDERBUFFER_DEPTH_SIZE,
            StencilSize = GL_RENDERBUFFER_STENCIL_SIZE,
        };

        static bool is_renderbuffer(GLuint id);
        static void unbind();

    public:
        Renderbuffer() = default;
        Renderbuffer(Renderbuffer &&from);
        ~Renderbuffer() override;
        BASE_DELETE_COPY_FUNCTION(Renderbuffer);

    public:
        Renderbuffer &operator=(Renderbuffer &&from);
        base::Int64 get_resource_type() const override;
        void bind() const;

    public:
        void create();
        void destroy();

    public:
        void set_storage(InternalFormat internal_format, GLsizei width, GLsizei height);
        void set_storage_multisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

    public:
        GLint get_parameter(ParameterName pname) const;
    };

    Renderbuffer create_renderbuffer(InternalFormat internal_format, base::Size width, base::Size height);

} // namespace gl_wrapper
