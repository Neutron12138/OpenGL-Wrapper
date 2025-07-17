#pragma once

#include "scissor_test_state.hpp"

namespace gl_wrapper
{
    ScissorTestState::ScissorTestState(GLboolean enabled, const glm::uvec2 &size)
        : is_scissor_test_enabled(enabled),
          scissor_size(size) {}
    ScissorTestState::ScissorTestState(GLboolean enabled, const glm::ivec2 &origin, const glm::uvec2 &size)
        : is_scissor_test_enabled(enabled),
          scissor_origin(origin), scissor_size(size) {}

    void ScissorTestState::operator()() const
    {
        if (!is_scissor_test_enabled)
        {
            glDisable(GL_SCISSOR_TEST);
            return;
        }

        glEnable(GL_SCISSOR_TEST);
        glScissor(scissor_origin.x, scissor_origin.y, scissor_size.x, scissor_size.y);
    }

} // namespace gl_wrapper
