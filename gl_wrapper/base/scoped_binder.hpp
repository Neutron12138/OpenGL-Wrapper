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
        Function m_current_binder = nullptr;
        /// @brief 当前解绑器
        Function m_current_unbinder = nullptr;
        /// @brief 先前绑定器
        Function m_previous_binder = nullptr;
        /// @brief 先前解绑器
        Function m_previous_unbinder = nullptr;

    private:
        void _bind()
        {
            if (m_previous_unbinder)
                m_previous_unbinder();

            if (m_current_binder)
                m_current_binder();
        }

        void _unbind()
        {
            if (m_current_unbinder)
                m_current_unbinder();

            if (m_previous_binder)
                m_previous_binder();
        }

    public:
        template <typename T>
        inline ScopedBinder(T *current, T *previous)
            : m_current_binder([=]()
                               { if(current) current->bind(); }),
              m_current_unbinder([=]()
                                 { if(current) current->unbind(); }),
              m_previous_binder([=]()
                                { if(previous) previous->bind(); }),
              m_previous_unbinder([=]()
                                  { if(previous) previous->unbind(); }) { _bind(); }

        template <typename T>
        inline ScopedBinder(T *current, std::nullptr_t)
            : m_current_binder([=]()
                               { if(current) current->bind(); }),
              m_current_unbinder([=]()
                                 { if(current) current->unbind(); }) { _bind(); }

        template <typename T>
        inline ScopedBinder(std::nullptr_t, T *previous)
            : m_previous_binder([=]()
                                { if(previous) previous->bind(); }),
              m_previous_unbinder([=]()
                                  { if(previous) previous->unbind(); }) { _bind(); }

        template <typename F1, typename F2, typename F3, typename F4>
        inline ScopedBinder(F1 current_binder, F2 current_unbinder,
                            F3 previous_binder, F4 previous_unbinder)
            : m_current_binder(current_binder),
              m_current_unbinder(current_unbinder),
              m_previous_binder(previous_binder),
              m_previous_unbinder(previous_unbinder) { _bind(); }

        inline ~ScopedBinder() { _unbind(); }

    public:
        Function get_current_binder() const { return m_current_binder; }
        Function get_current_unbinder() const { return m_current_unbinder; }
        Function get_previous_binder() const { return m_previous_binder; }
        Function get_previous_unbinder() const { return m_previous_unbinder; }
    };

} // namespace gl_wrapper
