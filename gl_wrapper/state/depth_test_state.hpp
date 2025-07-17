#pragma once

#include "../base/gl_loader.hpp"
#include "../base/enums.hpp"

namespace gl_wrapper
{
    /// @brief 深度测试状态
    class DepthTestState
    {
    public:
        /// @brief 是否启用深度测试
        GLboolean is_depth_test_enabled = GL_TRUE;
        /// @brief 深度函数
        CompareFunction depth_func = CompareFunction::Less;
        /// @brief 深度掩码
        GLboolean depth_flag = GL_TRUE;

    public:
        DepthTestState() = default;
        DepthTestState(GLboolean enabled, CompareFunction func = CompareFunction::Less, GLboolean flag = GL_TRUE);
        ~DepthTestState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
