#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 模板测试状态
    class StencilTestState
    {
    public:
        /// @brief 是否启用模板测试
        GLboolean is_stencil_test_enabled = GL_FALSE;
        /// @brief 要进行模板测试的面
        GLenum stencil_face = GL_FRONT_AND_BACK;
        /// @brief 模板掩码
        GLuint stencil_mask = 0xFF;
        /// @brief 模板函数
        GLenum stencil_func = GL_ALWAYS;
        /// @brief 模板测试参考值
        GLint stencil_func_ref = 0x00;
        /// @brief 模板函数掩码
        GLuint stencil_func_mask = 0xFF;
        /// @brief 当模板测试失败时
        GLenum stencil_test_fail = GL_KEEP;
        /// @brief 当模板测试通过，但深度测试失败时
        GLenum stencil_depth_test_fail = GL_KEEP;
        /// @brief 当模板测试与深度测试都通过时
        GLenum stencil_depth_test_pass = GL_REPLACE;

    public:
        constexpr StencilTestState() = default;
        constexpr StencilTestState(GLboolean enabled, GLuint mask, GLenum func, GLint ref, GLuint func_mask)
            : is_stencil_test_enabled(enabled),
              stencil_mask(mask),
              stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask) {}
        constexpr StencilTestState(GLboolean enabled, GLuint mask, GLenum func, GLint ref,
                                   GLuint func_mask, GLenum sfail, GLenum dpfail, GLenum dppass)
            : is_stencil_test_enabled(enabled),
              stencil_mask(mask),
              stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask),
              stencil_test_fail(sfail), stencil_depth_test_fail(dpfail), stencil_depth_test_pass(dppass) {}
        constexpr StencilTestState(GLboolean enabled, GLenum face, GLuint mask, GLenum func, GLint ref,
                                   GLuint func_mask, GLenum sfail, GLenum dpfail, GLenum dppass)
            : is_stencil_test_enabled(enabled), stencil_face(face),
              stencil_mask(mask),
              stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask),
              stencil_test_fail(sfail), stencil_depth_test_fail(dpfail), stencil_depth_test_pass(dppass) {}
        inline ~StencilTestState() = default;

    public:
        void operator()() const
        {
            if (!is_stencil_test_enabled)
            {
                glDisable(GL_STENCIL_TEST);
                return;
            }

            glEnable(GL_STENCIL_TEST);
            glStencilMaskSeparate(stencil_face, stencil_mask);
            glStencilFuncSeparate(stencil_face, stencil_func, stencil_func_ref, stencil_func_mask);
            glStencilOpSeparate(stencil_face, stencil_test_fail, stencil_depth_test_fail, stencil_depth_test_pass);
        }
    };

} // namespace gl_wrapper
