#pragma once

#include "debug_message_callback.hpp"

#define GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_UNKNOWN_ENUM \
    default:                                           \
        os << "Unknown";                               \
        break;

#define GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(name) \
    case ::gl_wrapper::DebugMessageCallback::Source::name: \
        os << #name;                                       \
        break;

#define GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(name) \
    case ::gl_wrapper::DebugMessageCallback::Type::name: \
        os << #name;                                     \
        break;

#define GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SEVERITY(name) \
    case ::gl_wrapper::DebugMessageCallback::Severity::name: \
        os << #name;                                         \
        break;

namespace gl_wrapper
{
    DebugMessageCallback &DebugMessageCallback::get_instance()
    {
        static DebugMessageCallback instance;
        return instance;
    }

    DebugMessageCallback::DebugMessageCallback()
    {
        if (!glGetString)
            throw BASE_MAKE_RUNTIME_ERROR("OpenGL has not been initialized yet");

        glDebugMessageCallback(_debug_message_callback, nullptr);
        m_callbacks.push_back(Function(_default_debug_message_callback));
    }

    DebugMessageCallback::~DebugMessageCallback() { glDebugMessageCallback(nullptr, nullptr); }

    void DebugMessageCallback::_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                                       GLsizei length, const GLchar *message, const void *userParam)
    {
        for (auto &callback : get_instance().m_callbacks)
            callback(static_cast<Source>(source), static_cast<Type>(type), id,
                     static_cast<Severity>(severity), length, message);
    }

    void DebugMessageCallback::_default_debug_message_callback(
        Source source, Type type, GLuint id, Severity severity,
        GLsizei length, const GLchar *message)
    {
        std::cout << "[OpenGL Debug Message]" << std::endl
                  << "source: " << source << std::endl
                  << "type: " << type << std::endl
                  << "id: " << id << std::endl
                  << "severity: " << severity << std::endl
                  << "message: " << message << std::endl;
    }

    const DebugMessageCallback::CallbackArray &DebugMessageCallback::get_callbacks() const { return m_callbacks; }

    void DebugMessageCallback::remove_callback(CallbackConstIterator iter) { m_callbacks.erase(iter); }

    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Source source)
    {
        switch (source)
        {
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(API);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(WindowSystem);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(ShaderCompiler);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(ThirdParty);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(Application);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SOURCE(Other);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_UNKNOWN_ENUM;
        }

        return os;
    }

    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Type type)
    {
        switch (type)
        {
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(Error);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(DeprecatedBehavior);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(UndefinedBehavior);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(Portability);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(Performance);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(Marker);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(PushGroup);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(PopGroup);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_TYPE(Other);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_UNKNOWN_ENUM;
        };

        return os;
    }

    std::ostream &operator<<(std::ostream &os, DebugMessageCallback::Severity severity)
    {
        switch (severity)
        {
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SEVERITY(Low);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SEVERITY(Medium);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SEVERITY(High);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_STR_SEVERITY(Notification);
            GL_WRAPPER_DEBUG_MESSAGE_CALLBACK_UNKNOWN_ENUM;
        }

        return os;
    }

} // namespace gl_wrapper
