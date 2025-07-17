#pragma once

#include "../base/gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief 面剔除状态
    class CullFaceState
    {
    public:
        /// @brief 剔除面
        enum class CullFace : GLenum
        {
            Front = GL_FRONT,
            Back = GL_BACK,
            FrontAndBack = GL_FRONT_AND_BACK,
        };

        /// @brief 前面
        enum class FrontFace : GLenum
        {
            CW = GL_CW,
            CCW = GL_CCW,
        };

    public:
        /// @brief 是否启用面剔除
        GLboolean is_cull_face_enabled = GL_TRUE;
        /// @brief 正面环绕方式
        FrontFace front_face = FrontFace::CCW;
        /// @brief 要剔除的面
        CullFace cull_face = CullFace::Back;

    public:
        CullFaceState() = default;
        CullFaceState(GLboolean enabled, FrontFace front = FrontFace::CCW, CullFace cull = CullFace::Back);
        ~CullFaceState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
