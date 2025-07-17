#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 清除状态
    class ClearState
    {
    public:
        /// @brief 清除颜色
        glm::vec4 clear_color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        /// @brief 清除深度
        GLdouble clear_depth = 1.0;
        /// @brief 清除模板
        GLint clear_stencil = 0;

    public:
        ClearState() = default;
        ClearState(const glm::vec4 &color, GLdouble depth = 1.0, GLint stencil = 0);
        ~ClearState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
