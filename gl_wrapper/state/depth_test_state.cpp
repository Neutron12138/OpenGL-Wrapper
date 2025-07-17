#pragma once

#include "depth_test_state.hpp"

namespace gl_wrapper
{
    DepthTestState::DepthTestState(GLboolean enabled, CompareFunction func, GLboolean flag)
        : is_depth_test_enabled(enabled), depth_func(func), depth_flag(flag) {}

    void DepthTestState::operator()() const
    {
        if (!is_depth_test_enabled)
        {
            glDisable(GL_DEPTH_TEST);
            return;
        }

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(static_cast<GLenum>(depth_func));
        glDepthMask(depth_flag);
    }

} // namespace gl_wrapper
