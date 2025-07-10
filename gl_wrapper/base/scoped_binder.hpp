#pragma once

#include "bindable.hpp"

namespace gl_wrapper
{
    /// @brief 范围绑定器，在一个作用域内自动绑定BindableResource
    class ScopedBinder : public base::NoncopyableObject
    {
    private:
        /// @brief 当前绑定
        Bindable *m_current = nullptr;
        /// @brief 先前绑定
        Bindable *m_previous = nullptr;

    public:
        ScopedBinder(Bindable *current, Bindable *previous = nullptr)
            : m_current(current), m_previous(previous)
        {
            if (m_previous)
                m_previous->unbind();

            if (m_current)
                m_current->bind();
        }

        ~ScopedBinder()
        {
            if (m_current)
                m_current->unbind();

            if (m_previous)
                m_previous->bind();
        }
    };

} // namespace gl_wrapper
