#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 深度测试状态
    class DepthTestState
    {
    public:
        /// @brief 是否启用深度测试
        GLboolean is_depth_test_enabled = GL_TRUE;
        /// @brief 深度函数
        GLenum depth_func = GL_LESS;
        /// @brief 深度掩码
        GLboolean depth_flag = GL_TRUE;

    public:
        constexpr DepthTestState() = default;
        constexpr DepthTestState(GLboolean enabled, GLenum func = GL_LESS, GLboolean flag = GL_TRUE)
            : is_depth_test_enabled(enabled), depth_func(func), depth_flag(flag) {}
        inline ~DepthTestState() = default;

    public:
        void operator()() const
        {
            if (!is_depth_test_enabled)
            {
                glDisable(GL_DEPTH_TEST);
                return;
            }

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(depth_func);
            glDepthMask(depth_flag);
        }
    };

} // namespace gl_wrapper
