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
        Context()
        {
            if (!glGetString)
                throw BASE_MAKE_RUNTIME_ERROR("OpenGL has not been initialized yet");
        }

    public:
        ~Context() = default;

    public: // 启用/禁用功能
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
        inline void set_multi_sample(bool enabled) const { set_enabled(GL_MULTISAMPLE, enabled); }

    public: // 清除
        inline void clear_color(const glm::vec4 &color) const { glClearColor(color.r, color.g, color.b, color.a); }
        inline void clear_depth(double depth) const { glClearDepth(depth); }
        inline void clear_stencil(GLint s) const { glClearStencil(s); }

    public: // 深度测试
        inline void set_depth_test(bool enabled) const { set_enabled(GL_DEPTH_TEST, enabled); }
        inline void depth_mask(bool flag) const { glDepthMask(flag); }
        inline void depth_func(GLenum func) const { glDepthFunc(func); }

    public: // 模板测试
        inline void set_stencil_test(bool enabled) const { set_enabled(GL_STENCIL_TEST, enabled); }
        inline void stencil_mask(GLuint mask) const { glStencilMask(mask); }
        inline void stencil_func(GLenum func, GLint ref, GLuint mask) const { glStencilFunc(func, ref, mask); }
        inline void stencil_op(GLenum fail, GLenum zfail, GLenum zpass) const { glStencilOp(fail, zfail, zpass); }

    public: // 混合
        inline void set_blend(bool enabled) const { set_enabled(GL_BLEND, enabled); }
        inline void blend_func(GLenum sfactor, GLenum dfactor) const { glBlendFunc(sfactor, dfactor); }
        inline void blend_func_separate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) const
        {
            glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
        }

    public: // 面剔除
        inline void set_cull_face(bool enabled) const { set_enabled(GL_CULL_FACE, enabled); }
        inline void cull_face(GLenum mode) const { glCullFace(mode); }
        inline void front_face(GLenum mode) const { glFrontFace(mode); }
    };

} // namespace gl_wrapper
