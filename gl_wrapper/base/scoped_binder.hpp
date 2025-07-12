#pragma once

#include <functional>
#include <base/core/noncopyable_object.hpp>

namespace gl_wrapper
{
    /// @brief 在作用域内自动绑定资源
    class ScopedBinder : public base::NoncopyableObject
    {
    public:
        using BindingFunc = void();
        using Function = std::function<BindingFunc>;

    private:
        /// @brief 当前绑定器
        Function m_binder = nullptr;
        /// @brief 当前解绑器
        Function m_unbinder = nullptr;

    private:
        void _bind()
        {
            if (m_binder)
                m_binder();
        }

        void _unbind()
        {
            if (m_unbinder)
                m_unbinder();
        }

    public:
        template <typename F1, typename F2>
        inline ScopedBinder(F1 binder, F2 unbinder)
            : m_binder(binder), m_unbinder(unbinder) { _bind(); }
        inline ScopedBinder(ScopedBinder &&from)
            : m_binder(std::exchange(from.m_binder, nullptr)),
              m_unbinder(std::exchange(from.m_unbinder, nullptr)) { _bind(); }
        inline ~ScopedBinder() { _unbind(); }

    public:
        Function get_binder() const { return m_binder; }
        Function get_unbinder() const { return m_unbinder; }
    };

} // namespace gl_wrapper
