#pragma once

#include "scoped_binder.hpp"

namespace gl_wrapper
{
    void ScopedBinder::_bind()
    {
        if (m_binder)
            m_binder();
    }

    void ScopedBinder::_unbind()
    {
        if (m_unbinder)
            m_unbinder();
    }

    ScopedBinder::ScopedBinder(ScopedBinder &&from)
        : m_binder(std::exchange(from.m_binder, nullptr)),
          m_unbinder(std::exchange(from.m_unbinder, nullptr)) { _bind(); }

    ScopedBinder::~ScopedBinder() { _unbind(); }

    ScopedBinder::Function ScopedBinder::get_binder() const { return m_binder; }
    ScopedBinder::Function ScopedBinder::get_unbinder() const { return m_unbinder; }

} // namespace gl_wrapper
