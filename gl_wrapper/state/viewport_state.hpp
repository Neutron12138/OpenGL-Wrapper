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
        constexpr ViewportState(const glm::uvec2 &size)
            : viewport_size(size) {}
        constexpr ViewportState(const glm::ivec2 &origin, const glm::uvec2 &size)
            : viewport_origin(origin), viewport_size(size) {}
        inline ~ViewportState() = default;

    public:
        inline void operator()() const { glViewport(viewport_origin.x, viewport_origin.y, viewport_size.x, viewport_size.y); }
    };

} // namespace gl_wrapper
