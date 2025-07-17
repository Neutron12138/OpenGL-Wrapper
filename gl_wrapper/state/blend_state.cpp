#pragma once

#include "blend_state.hpp"

namespace gl_wrapper
{
    BlendState::BlendState(GLboolean enabled, Func src, Func dst)
        : is_blend_enabled(enabled),
          blend_src_RGB(src), blend_dst_RGB(dst),
          blend_src_alpha(src), blend_dst_alpha(dst) {}
    BlendState::BlendState(GLboolean enabled, Func src_RGB, Func dst_RGB, Func src_alpha, Func dst_alpha)
        : is_blend_enabled(enabled),
          blend_src_RGB(src_RGB), blend_dst_RGB(dst_RGB),
          blend_src_alpha(src_alpha), blend_dst_alpha(dst_alpha) {}
    BlendState::BlendState(GLboolean enabled, Equation equation, const glm::vec4 &color,
                           Func src_RGB, Func dst_RGB, Func src_alpha, Func dst_alpha)
        : is_blend_enabled(enabled), blend_equation(equation), blend_color(color),
          blend_src_RGB(src_RGB), blend_dst_RGB(dst_RGB),
          blend_src_alpha(src_alpha), blend_dst_alpha(dst_alpha) {}

    void BlendState::operator()() const
    {
        if (!is_blend_enabled)
        {
            glDisable(GL_BLEND);
            return;
        }

        glEnable(GL_BLEND);
        glBlendEquation(static_cast<GLenum>(blend_equation));
        glBlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a);
        glBlendFuncSeparate(static_cast<GLenum>(blend_src_RGB), static_cast<GLenum>(blend_dst_RGB),
                            static_cast<GLenum>(blend_src_alpha), static_cast<GLenum>(blend_dst_alpha));
    }

} // namespace gl_wrapper
