#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <base/core/noncopyable_object.hpp>
#include "gl_loader.hpp"

namespace gl_wrapper
{
    /// @brief OpenGL调试消息回调管理器
    class DebugMessageCallback : public base::NoncopyableObject
    {
    public:
        using DebugMessageFunc = void(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
        using Function = std::function<DebugMessageFunc>;
        using CallbackArray = std::vector<Function>;
        using CallbackConstIterator = CallbackArray::const_iterator;

        /// @brief 获取实例
        /// @return 实例
        static DebugMessageCallback &get_instance()
        {
            static DebugMessageCallback instance;
            return instance;
        }

    private:
        /// @brief 回调数组
        CallbackArray m_callbacks = {};

    private:
        inline DebugMessageCallback()
        {
            if (!glGetString)
                throw BASE_MAKE_RUNTIME_ERROR("OpenGL has not been initialized yet");

            glDebugMessageCallback(_debug_message_callback, nullptr);
            m_callbacks.push_back(Function(_default_debug_message_callback));
        }

    public:
        inline ~DebugMessageCallback() { glDebugMessageCallback(nullptr, nullptr); }

    private:
        static inline void _debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                                   GLsizei length, const GLchar *message, const void *userParam)
        {
            for (auto &callback : get_instance().m_callbacks)
                callback(source, type, id, severity, length, message, userParam);
        }

        static inline void _default_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                                           GLsizei length, const GLchar *message, const void *userParam)
        {
            std::cout << "[OpenGL Debug Message]" << std::endl
                      << "source: " << source << std::endl
                      << "type: " << type << std::endl
                      << "id: " << id << std::endl
                      << "severity: " << severity << std::endl
                      << "message: " << message << std::endl;
        }

    public:
        inline const CallbackArray &get_callbacks() const { return m_callbacks; }

    public:
        template <typename F>
        inline void add_callback(F callback) { m_callbacks.push_back(Function(callback)); }
        inline void remove_callback(CallbackConstIterator iter) { m_callbacks.erase(iter); }
    };

} // namespace gl_wrapper
