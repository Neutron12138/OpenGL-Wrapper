#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 混合状态
    class BlendState
    {
    public:
        /// @brief 是否启用混合
        GLboolean is_blend_enabled = GL_TRUE;
        /// @brief 混合方程
        GLenum blend_equation = GL_FUNC_ADD;
        /// @brief 混合颜色
        glm::vec4 blend_color = glm::vec4(0.0f);
        /// @brief 源颜色
        GLenum blend_src_RGB = GL_SRC_ALPHA;
        /// @brief 目标颜色
        GLenum blend_dst_RGB = GL_ONE_MINUS_SRC_ALPHA;
        /// @brief 源透明度
        GLenum blend_src_alpha = GL_SRC_ALPHA;
        /// @brief 目标透明度
        GLenum blend_dst_alpha = GL_ONE_MINUS_SRC_ALPHA;

    public:
        constexpr BlendState() = default;
        constexpr BlendState(GLboolean enabled, GLenum src, GLenum dst)
            : is_blend_enabled(enabled),
              blend_src_RGB(src), blend_dst_RGB(dst),
              blend_src_alpha(src), blend_dst_alpha(dst) {}
        constexpr BlendState(GLboolean enabled, GLenum src_RGB, GLenum dst_RGB, GLenum src_alpha, GLenum dst_alpha)
            : is_blend_enabled(enabled),
              blend_src_RGB(src_RGB), blend_dst_RGB(dst_RGB),
              blend_src_alpha(src_alpha), blend_dst_alpha(dst_alpha) {}
        constexpr BlendState(GLboolean enabled, GLenum equation, const glm::vec4 &color,
                             GLenum src_RGB, GLenum dst_RGB, GLenum src_alpha, GLenum dst_alpha)
            : is_blend_enabled(enabled), blend_equation(equation), blend_color(color),
              blend_src_RGB(src_RGB), blend_dst_RGB(dst_RGB),
              blend_src_alpha(src_alpha), blend_dst_alpha(dst_alpha) {}
        inline ~BlendState() = default;

    public:
        void operator()() const
        {
            if (!is_blend_enabled)
            {
                glDisable(GL_BLEND);
                return;
            }

            glEnable(GL_BLEND);
            glBlendEquation(blend_equation);
            glBlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a);
            glBlendFuncSeparate(blend_src_RGB, blend_dst_RGB, blend_src_alpha, blend_dst_alpha);
        }
    };

} // namespace gl_wrapper
