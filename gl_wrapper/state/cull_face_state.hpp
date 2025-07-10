#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 面剔除状态
    class CullFaceState
    {
    public:
        /// @brief 是否启用面剔除
        GLboolean is_cull_face_enabled = GL_TRUE;
        /// @brief 正面环绕方式
        GLenum front_face = GL_CCW;
        /// @brief 要剔除的面
        GLenum cull_face = GL_BACK;

    public:
        constexpr CullFaceState() = default;
        constexpr CullFaceState(GLboolean enabled, GLenum front = GL_CCW, GLenum cull = GL_BACK)
            : is_cull_face_enabled(enabled), front_face(front), cull_face(cull) {}
        inline ~CullFaceState() = default;

    public:
        void operator()() const
        {
            if (!is_cull_face_enabled)
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
