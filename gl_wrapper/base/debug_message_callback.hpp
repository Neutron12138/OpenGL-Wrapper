#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <base/misc/noncopyable_object.hpp>
#include "gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief OpenGL调试消息回调管理器
    class DebugMessageCallback : public base::NoncopyableObject
    {
    public:
        /// @brief 消息源
        enum class Source : GLenum
        {
            DontCare = GL_DONT_CARE,
            API = GL_DEBUG_SOURCE_API,
            WindowSystem = GL_DEBUG_SOURCE_WINDOW_SYSTEM,
            ShaderCompiler = GL_DEBUG_SOURCE_SHADER_COMPILER,
            ThirdParty = GL_DEBUG_SOURCE_THIRD_PARTY,
            Application = GL_DEBUG_SOURCE_APPLICATION,
            Other = GL_DEBUG_SOURCE_OTHER,
        };

        /// @brief 消息类型
        enum class Type : GLenum
        {
            DontCare = GL_DONT_CARE,
            Error = GL_DEBUG_TYPE_ERROR,
            DeprecatedBehavior = GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR,
            UndefinedBehavior = GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR,
            Portability = GL_DEBUG_TYPE_PORTABILITY,
            Performance = GL_DEBUG_TYPE_PERFORMANCE,
            Marker = GL_DEBUG_TYPE_MARKER,
            PushGroup = GL_DEBUG_TYPE_PUSH_GROUP,
            PopGroup = GL_DEBUG_TYPE_POP_GROUP,
            Other = GL_DEBUG_TYPE_OTHER,
        };

        /// @brief 消息严重性
        enum class Severity : GLenum
        {
            DontCare = GL_DONT_CARE,
            Low = GL_DEBUG_SEVERITY_LOW,
            Medium = GL_DEBUG_SEVERITY_MEDIUM,
            High = GL_DEBUG_SEVERITY_HIGH,
            Notification = GL_DEBUG_SEVERITY_NOTIFICATION,
        };

        using DebugMessageFunc = void(Source source, Type type, GLuint id, Severity severity,
                                      GLsizei length, const GLchar *message);
        using Function = std::function<DebugMessageFunc>;
        using CallbackArray = std::vector<Function>;
        using CallbackConstIterator = CallbackArray::const_iterator;

        /// @brief 获取实例
        /// @return 实例
        static DebugMessageCallback &get_instance();

    private:
        /// @brief 回调数组
        CallbackArray m_callbacks = {};

    private:
        DebugMessageCallback();

    public:
        ~DebugMessageCallback();
        BASE_DELETE_COPY_FUNCTION(DebugMessageCallback);

    private:
        static void _debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                            GLsizei length, const GLchar *message, const void *userParam);
        static void _default_debug_message_callback(Source source, Type type, GLuint id, Severity severity,
                                                    GLsizei length, const GLchar *message);

    public:
        const CallbackArray &get_callbacks() const;

    public:
        template <typename F>
        inline void add_callback(F callback) { m_callbacks.push_back(Function(callback)); }
        void remove_callback(CallbackConstIterator iter);
    };

    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Source source);
    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Type type);
    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Severity severity);

} // namespace gl_wrapper
