#pragma once

#include "resource.hpp"

namespace gl_wrapper
{
    Resource::Resource(Resource &&from) : m_id(std::exchange(from.m_id, 0)) {}
    Resource::~Resource() { m_id = 0; }

    Resource &Resource::operator=(Resource &&from)
    {
        m_id = std::exchange(from.m_id, 0);
        return *this;
    }

    Resource::operator GLuint() const { return m_id; }
    GLuint Resource::get_id() const { return m_id; }
    bool Resource::is_valid() const { return m_id; }

} // namespace gl_wrapper
