#pragma once

#include "query.hpp"

namespace gl_wrapper
{
    bool Query::is_query(GLuint id) { return glIsQuery(id); }

    Query::Query(QueryType type) { create(type); }
    Query::Query(Query &&from)
        : Resource(std::move(from)),
          m_type(std::exchange(from.m_type, QueryType::None)) {}
    Query::~Query() { destroy(); }

    Query &Query::operator=(Query &&from)
    {
        destroy();
        m_id = std::exchange(from.m_id, 0);
        m_type = std::exchange(from.m_type, QueryType::None);
        return *this;
    }

    base::Int64 Query::get_resource_type() const { return static_cast<base::Int64>(ResourceType::Query); }
    Query::QueryType Query::get_type() const { return m_type; }

    void Query::create(QueryType type)
    {
        destroy();

        glCreateQueries(static_cast<GLenum>(type), 1, &m_id);
        if (m_id == 0)
            throw BASE_MAKE_RUNTIME_ERROR("Failed to create Query object");

        m_type = type;
    }

    void Query::destroy()
    {
        if (m_id == 0)
            return;

        glDeleteQueries(1, &m_id);
        m_type = QueryType::None;
    }

    void Query::begin() { glBeginQuery(static_cast<GLenum>(m_type), m_id); }
    void Query::end() { glEndQuery(static_cast<GLenum>(m_type)); }
    void Query::begin_indexed(GLuint index) { glBeginQueryIndexed(static_cast<GLenum>(m_type), index, m_id); }
    void Query::end_indexed(GLuint index) { glEndQueryIndexed(static_cast<GLenum>(m_type), index); }

    template <>
    GLint Query::get_parameter(ParameterName pname) const
    {
        GLint param;
        glGetQueryObjectiv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    template <>
    GLuint Query::get_parameter(ParameterName pname) const
    {
        GLuint param;
        glGetQueryObjectuiv(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

    template <>
    GLint64 Query::get_parameter(ParameterName pname) const
    {
        GLint64 param;
        glGetQueryObjecti64v(m_id, static_cast<GLenum>(pname), &param);
        return param;
    }

} // namespace gl_wrapper
