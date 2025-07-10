#include <glm/gtc/type_ptr.hpp>
#include "program.hpp"

namespace gl_wrapper
{
    //
    // scalar
    //

    template <>
    GLint Program::get_uniform(GLint location)
    {
        GLint result;
        glGetUniformiv(m_id, location, &result);
        return result;
    }

    template <>
    GLuint Program::get_uniform(GLint location)
    {
        GLuint result;
        glGetUniformuiv(m_id, location, &result);
        return result;
    }

    template <>
    GLfloat Program::get_uniform(GLint location)
    {
        GLfloat result;
        glGetUniformfv(m_id, location, &result);
        return result;
    }

    template <>
    GLdouble Program::get_uniform(GLint location)
    {
        GLdouble result;
        glGetUniformdv(m_id, location, &result);
        return result;
    }

    //
    // vec2
    //

    template <>
    glm::ivec2 Program::get_uniform(GLint location)
    {
        glm::ivec2 result;
        glGetUniformiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec2 Program::get_uniform(GLint location)
    {
        glm::uvec2 result;
        glGetUniformuiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec2 Program::get_uniform(GLint location)
    {
        glm::vec2 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec2 Program::get_uniform(GLint location)
    {
        glm::dvec2 result;
        glGetUniformdv(m_id, location, glm::value_ptr(result));
        return result;
    }

    //
    // vec3
    //

    template <>
    glm::ivec3 Program::get_uniform(GLint location)
    {
        glm::ivec3 result;
        glGetUniformiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec3 Program::get_uniform(GLint location)
    {
        glm::uvec3 result;
        glGetUniformuiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec3 Program::get_uniform(GLint location)
    {
        glm::vec3 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec3 Program::get_uniform(GLint location)
    {
        glm::dvec3 result;
        glGetUniformdv(m_id, location, glm::value_ptr(result));
        return result;
    }

    //
    // vec4
    //

    template <>
    glm::ivec4 Program::get_uniform(GLint location)
    {
        glm::ivec4 result;
        glGetUniformiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec4 Program::get_uniform(GLint location)
    {
        glm::uvec4 result;
        glGetUniformuiv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec4 Program::get_uniform(GLint location)
    {
        glm::vec4 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec4 Program::get_uniform(GLint location)
    {
        glm::dvec4 result;
        glGetUniformdv(m_id, location, glm::value_ptr(result));
        return result;
    }

    //
    // matrix
    //

    template <>
    glm::mat2 Program::get_uniform(GLint location)
    {
        glm::mat2 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat2x3 Program::get_uniform(GLint location)
    {
        glm::mat2x3 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat2x4 Program::get_uniform(GLint location)
    {
        glm::mat2x4 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3 Program::get_uniform(GLint location)
    {
        glm::mat3 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3x2 Program::get_uniform(GLint location)
    {
        glm::mat3x2 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3x4 Program::get_uniform(GLint location)
    {
        glm::mat3x4 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4 Program::get_uniform(GLint location)
    {
        glm::mat4 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4x2 Program::get_uniform(GLint location)
    {
        glm::mat4x2 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4x3 Program::get_uniform(GLint location)
    {
        glm::mat4x3 result;
        glGetUniformfv(m_id, location, glm::value_ptr(result));
        return result;
    }

} // namespace gl_wrapper
