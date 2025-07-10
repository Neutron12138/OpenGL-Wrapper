#pragma once

#include <glm/glm.hpp>
#include "gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief OpenGL上下文
    class Context : public base::NoncopyableObject
    {
    public:
        static Context &get_instance()
        {
            static Context instance;
            return instance;
        }

    private:
        inline Context()
        {
            if (!glGetString)
                throw BASE_MAKE_RUNTIME_ERROR("OpenGL has not been initialized yet");
        }

    public:
        inline ~Context() = default;

    public: // 启用/禁用功能
        inline bool is_enabled(GLenum cap) const { return glIsEnabled(cap); }
        inline void enable(GLenum cap) const { glEnable(cap); }
        inline void disable(GLenum cap) const { glDisable(cap); }
        inline void set_enabled(GLenum cap, bool enabled) const
        {
            if (enabled)
                enable(cap);
            else
                disable(cap);
        }

    public: // 多重采样
        inline void set_multisample(bool enabled) const { set_enabled(GL_MULTISAMPLE, enabled); }
        inline bool is_multisample_enabled() const { return is_enabled(GL_MULTISAMPLE); }

    public: // 清除
        inline void clear(GLbitfield mask) const { glClear(mask); }
        inline void clear_color(const glm::vec4 &color) const { glClearColor(color.r, color.g, color.b, color.a); }
        inline void clear_depth(double depth) const { glClearDepth(depth); }
        inline void clear_stencil(GLint s) const { glClearStencil(s); }

    public: // 视口
        inline void set_viewport(GLint x, GLint y, GLsizei width, GLsizei height) const { glViewport(x, y, width, height); }

    public: // 裁剪测试
        inline void set_scissor_test(bool enabled) const { set_enabled(GL_SCISSOR_TEST, enabled); }
        inline bool is_scissor_enabled() const { return is_enabled(GL_SCISSOR_TEST); }
        inline void set_scissor(GLint x, GLint y, GLsizei width, GLsizei height) const { glScissor(x, y, width, height); }

    public: // 深度测试
        inline void set_depth_test(bool enabled = true) const { set_enabled(GL_DEPTH_TEST, enabled); }
        inline bool is_depth_test_enabled() const { return is_enabled(GL_DEPTH_TEST); }
        inline void set_depth_mask(bool flag = GL_TRUE) const { glDepthMask(flag); }
        inline void set_depth_func(GLenum func = GL_LESS) const { glDepthFunc(func); }

    public: // 模板测试
        inline void set_stencil_test(bool enabled) const { set_enabled(GL_STENCIL_TEST, enabled); }
        inline bool is_stencil_test_enabled() const { return is_enabled(GL_STENCIL_TEST); }
        inline void set_stencil_mask(GLuint mask) const { glStencilMask(mask); }
        inline void set_stencil_func(GLenum func, GLint ref, GLuint mask) const { glStencilFunc(func, ref, mask); }
        inline void set_stencil_op(GLenum fail, GLenum zfail, GLenum zpass) const { glStencilOp(fail, zfail, zpass); }

    public: // 混合
        inline void set_blend(bool enabled) const { set_enabled(GL_BLEND, enabled); }
        inline bool is_blend_enabled() const { return is_enabled(GL_BLEND); }
        inline void set_blend_func(GLenum sfactor, GLenum dfactor) const { glBlendFunc(sfactor, dfactor); }
        inline void set_blend_func_separate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) const
        {
            glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
        }

    public: // 面剔除
        inline void set_cull_face(bool enabled = true) const { set_enabled(GL_CULL_FACE, enabled); }
        inline bool is_cull_face_enabled() const { return is_enabled(GL_CULL_FACE); }
        inline void set_cull_face(GLenum mode = GL_BACK) const { glCullFace(mode); }
        inline void set_front_face(GLenum mode) const { glFrontFace(mode); }
    };

} // namespace gl_wrapper
