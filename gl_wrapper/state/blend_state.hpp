#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 混合状态
    class BlendState
    {
    public:
        /// @brief 混合方程
        enum class Equation : GLenum
        {
            Add = GL_FUNC_ADD,
            Subtract = GL_FUNC_SUBTRACT,
            ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
            Min = GL_MIN,
            Max = GL_MAX,
        };

        /// @brief 混合函数
        enum class Func : GLenum
        {
            Zero = GL_ZERO,
            One = GL_ONE,
            SrcColor = GL_SRC_COLOR,
            OneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
            DstColor = GL_DST_COLOR,
            OneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
            SrcAlpha = GL_SRC_ALPHA,
            OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
            DstAlpha = GL_DST_ALPHA,
            OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
            ConstantColor = GL_CONSTANT_COLOR,
            OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
            ConstantAlpha = GL_CONSTANT_ALPHA,
            OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
        };

    public:
        /// @brief 是否启用混合
        GLboolean is_blend_enabled = GL_TRUE;
        /// @brief 混合方程
        Equation blend_equation = Equation::Add;
        /// @brief 混合颜色
        glm::vec4 blend_color = glm::vec4(0.0f);
        /// @brief 源颜色
        Func blend_src_RGB = Func::SrcAlpha;
        /// @brief 目标颜色
        Func blend_dst_RGB = Func::OneMinusSrcAlpha;
        /// @brief 源透明度
        Func blend_src_alpha = Func::SrcAlpha;
        /// @brief 目标透明度
        Func blend_dst_alpha = Func::OneMinusSrcAlpha;

    public:
        BlendState() = default;
        BlendState(GLboolean enabled, Func src, Func dst);
        BlendState(GLboolean enabled, Func src_RGB, Func dst_RGB, Func src_alpha, Func dst_alpha);
        BlendState(GLboolean enabled, Equation equation, const glm::vec4 &color,
                   Func src_RGB, Func dst_RGB, Func src_alpha, Func dst_alpha);
        ~BlendState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
