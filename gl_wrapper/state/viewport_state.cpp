#pragma once

#include "viewport_state.hpp"

namespace gl_wrapper
{
    ViewportState::ViewportState(const glm::uvec2 &size)
        : viewport_size(size) {}
    ViewportState::ViewportState(const glm::ivec2 &origin, const glm::uvec2 &size)
        : viewport_origin(origin), viewport_size(size) {}

    void ViewportState::operator()() const
    {
        glViewport(viewport_origin.x, viewport_origin.y, viewport_size.x, viewport_size.y);
    }

} // namespace gl_wrapper
