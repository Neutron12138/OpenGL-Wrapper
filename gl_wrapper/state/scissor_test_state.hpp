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
        constexpr ScissorTestState(GLboolean enabled, const glm::uvec2 &size)
            : is_scissor_test_enabled(enabled),
              scissor_size(size) {}
        constexpr ScissorTestState(GLboolean enabled, const glm::ivec2 &origin, const glm::uvec2 &size)
            : is_scissor_test_enabled(enabled),
              scissor_origin(origin), scissor_size(size) {}
        inline ~ScissorTestState() = default;

    public:
        void operator()() const
        {
            if (!is_scissor_test_enabled)
            {
                glDisable(GL_SCISSOR_TEST);
                return;
            }

            glEnable(GL_SCISSOR_TEST);
            glScissor(scissor_origin.x, scissor_origin.y, scissor_size.x, scissor_size.y);
        }
    };

} // namespace gl_wrapper
