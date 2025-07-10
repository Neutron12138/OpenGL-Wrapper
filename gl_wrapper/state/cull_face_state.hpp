#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 面剔除状态
    class CullFaceState
    {
    public:
        /// @brief 是否启用
        GLboolean enable = GL_TRUE;
        /// @brief 正面环绕方式
        GLenum front_face = GL_CCW;
        /// @brief 要剔除的面
        GLenum cull_face = GL_BACK;

    public:
        constexpr CullFaceState() = default;
        constexpr CullFaceState(GLboolean e, GLenum front = GL_CCW, GLenum cull = GL_BACK)
            : enable(e), front_face(front), cull_face(cull) {}
        inline ~CullFaceState() = default;

    public:
        void operator()() const
        {
            if (!enable)
            {
                glDisable(GL_CULL_FACE);
                return;
            }

            glEnable(GL_CULL_FACE);
            glFrontFace(front_face);
            glCullFace(cull_face);
        }
    };

} // namespace gl_wrapper
