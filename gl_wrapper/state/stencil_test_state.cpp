#pragma once

#include "stencil_test_state.hpp"

namespace gl_wrapper
{
    StencilTestState::StencilTestState(GLboolean enabled, GLuint mask, CompareFunction func, GLint ref, GLuint func_mask)
        : is_stencil_test_enabled(enabled),
          stencil_mask(mask),
          stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask) {}
    StencilTestState::StencilTestState(GLboolean enabled, GLuint mask, CompareFunction func, GLint ref,
                                       GLuint func_mask, Operation sfail, Operation dpfail, Operation dppass)
        : is_stencil_test_enabled(enabled),
          stencil_mask(mask),
          stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask),
          stencil_test_fail(sfail), stencil_depth_test_fail(dpfail), stencil_depth_test_pass(dppass) {}
    StencilTestState::StencilTestState(GLboolean enabled, GLenum face, GLuint mask, CompareFunction func, GLint ref,
                                       GLuint func_mask, Operation sfail, Operation dpfail, Operation dppass)
        : is_stencil_test_enabled(enabled), stencil_face(face),
          stencil_mask(mask),
          stencil_func(func), stencil_func_ref(ref), stencil_func_mask(func_mask),
          stencil_test_fail(sfail), stencil_depth_test_fail(dpfail), stencil_depth_test_pass(dppass) {}

    void StencilTestState::operator()() const
    {
        if (!is_stencil_test_enabled)
        {
            glDisable(GL_STENCIL_TEST);
            return;
        }

        glEnable(GL_STENCIL_TEST);
        glStencilMaskSeparate(stencil_face, stencil_mask);
        glStencilFuncSeparate(stencil_face, static_cast<GLenum>(stencil_func), stencil_func_ref, stencil_func_mask);
        glStencilOpSeparate(stencil_face, static_cast<GLenum>(stencil_test_fail),
                            static_cast<GLenum>(stencil_depth_test_fail), static_cast<GLenum>(stencil_depth_test_pass));
    }

} // namespace gl_wrapper
