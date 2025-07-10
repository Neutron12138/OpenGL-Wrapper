#pragma once

#include <functional>
#include <base/core/noncopyable_object.hpp>

namespace gl_wrapper
{
    /// @brief 在作用域内自动切换状态
    class ScopedState : public base::NoncopyableObject
    {
    public:
        using StateFunc = void();
        using Function = std::function<StateFunc>;

    private:
        /// @brief 当前状态
        Function m_current = nullptr;
        /// @brief 先前状态
        Function m_previous = nullptr;

    public:
        template <typename F1, typename F2>
        ScopedState(F1 current, F2 previous = nullptr)
            : m_current(current), m_previous(previous)
        {
            if (m_current)
                m_current();
        }

        ~ScopedState()
        {
            if (m_previous)
                m_previous();
        }

    public:
        Function get_current() const { return m_current; }
        Function get_previous() const { return m_previous; }
    };

} // namespace gl_wrapper
