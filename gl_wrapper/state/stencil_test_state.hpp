#pragma once

#include "../base/gl_loader.hpp"
#include "../base/enums.hpp"

namespace gl_wrapper
{
    /// @brief 模板测试状态
    class StencilTestState
    {
    public:
        /// @brief 模板操作
        enum class Operation : GLenum
        {
            Keep = GL_KEEP,
            Zero = GL_ZERO,
            Replace = GL_REPLACE,
            Incr = GL_INCR,
            IncrWrap = GL_INCR_WRAP,
            Decr = GL_DECR,
            DecrWrap = GL_DECR_WRAP,
            Invert = GL_INVERT,
        };

    public:
        /// @brief 是否启用模板测试
        GLboolean is_stencil_test_enabled = GL_FALSE;
        /// @brief 要进行模板测试的面
        GLenum stencil_face = GL_FRONT_AND_BACK;
        /// @brief 模板掩码
        GLuint stencil_mask = 0xFF;
        /// @brief 模板函数
        CompareFunction stencil_func = CompareFunction::Always;
        /// @brief 模板测试参考值
        GLint stencil_func_ref = 0x00;
        /// @brief 模板函数掩码
        GLuint stencil_func_mask = 0xFF;
        /// @brief 当模板测试失败时
        Operation stencil_test_fail = Operation::Keep;
        /// @brief 当模板测试通过，但深度测试失败时
        Operation stencil_depth_test_fail = Operation::Keep;
        /// @brief 当模板测试与深度测试都通过时
        Operation stencil_depth_test_pass = Operation::Replace;

    public:
        StencilTestState() = default;
        StencilTestState(GLboolean enabled, GLuint mask, CompareFunction func, GLint ref, GLuint func_mask);
        StencilTestState(GLboolean enabled, GLuint mask, CompareFunction func, GLint ref,
                         GLuint func_mask, Operation sfail, Operation dpfail, Operation dppass);
        StencilTestState(GLboolean enabled, GLenum face, GLuint mask, CompareFunction func, GLint ref,
                         GLuint func_mask, Operation sfail, Operation dpfail, Operation dppass);
        ~StencilTestState() = default;

    public:
        void operator()() const;
    };

} // namespace gl_wrapper
