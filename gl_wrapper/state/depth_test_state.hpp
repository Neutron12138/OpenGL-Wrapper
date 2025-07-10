#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 深度测试状态
    class DepthTestState
    {
    public:
        /// @brief 是否启用
        GLboolean enable = true;
        /// @brief 深度函数
        GLenum depth_func = GL_LESS;
        /// @brief 深度掩码
        GLboolean depth_flag = GL_TRUE;

    public:
        constexpr DepthTestState() = default;
        constexpr DepthTestState(GLboolean e, GLenum func = GL_LESS, GLboolean flag = GL_TRUE)
            : enable(e), depth_func(func), depth_flag(flag) {}
        inline ~DepthTestState() = default;

    public:
        void operator()() const
        {
            if (!enable)
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
