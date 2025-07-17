#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 裁剪测试状态
    class ScissorTestState
    {
    public:
        /// @brief 是否启用裁剪测试
        GLboolean is_scissor_test_enabled = GL_FALSE;
        /// @brief 裁剪区域原点
        glm::ivec2 scissor_origin = glm::ivec2(0);
        /// @brief 裁剪区域尺寸
        glm::uvec2 scissor_size;

    public:
        ScissorTestState(GLboolean enabled, const glm::uvec2 &size);
        ScissorTestState(GLboolean enabled, const glm::ivec2 &origin, const glm::uvec2 &size);
        ~ScissorTestState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
