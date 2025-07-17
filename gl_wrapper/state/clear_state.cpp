#pragma once

#include "clear_state.hpp"

namespace gl_wrapper
{
    ClearState::ClearState(const glm::vec4 &color, GLdouble depth, GLint stencil)
        : clear_color(color), clear_depth(depth), clear_stencil(stencil) {}

    void ClearState::operator()() const
    {
        glClearColor(clear_color.r, clear_color.g, clear_color.b, clear_color.a);
        glClearDepth(clear_depth);
        glClearStencil(clear_stencil);
    }

} // namespace gl_wrapper
