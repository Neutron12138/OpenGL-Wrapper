#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 视口状态
    class ViewportState
    {
    public:
        /// @brief 视口原点坐标
        glm::ivec2 viewport_origin = glm::ivec2(0);
        /// @brief 视口尺寸
        glm::uvec2 viewport_size;

    public:
        ViewportState(const glm::uvec2 &size);
        ViewportState(const glm::ivec2 &origin, const glm::uvec2 &size);
        ~ViewportState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
