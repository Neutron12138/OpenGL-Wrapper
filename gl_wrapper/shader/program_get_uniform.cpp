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
        glGetnUniformiv(m_id, location, sizeof(GLint), &result);
        return result;
    }

    template <>
    GLuint Program::get_uniform(GLint location)
    {
        GLuint result;
        glGetnUniformuiv(m_id, location, sizeof(GLuint), &result);
        return result;
    }

    template <>
    GLfloat Program::get_uniform(GLint location)
    {
        GLfloat result;
        glGetnUniformfv(m_id, location, sizeof(GLfloat), &result);
        return result;
    }

    template <>
    GLdouble Program::get_uniform(GLint location)
    {
        GLdouble result;
        glGetnUniformdv(m_id, location, sizeof(GLdouble), &result);
        return result;
    }

    //
    // vec2
    //

    template <>
    glm::ivec2 Program::get_uniform(GLint location)
    {
        glm::ivec2 result;
        glGetnUniformiv(m_id, location, sizeof(glm::ivec2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec2 Program::get_uniform(GLint location)
    {
        glm::uvec2 result;
        glGetnUniformuiv(m_id, location, sizeof(glm::uvec2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec2 Program::get_uniform(GLint location)
    {
        glm::vec2 result;
        glGetnUniformfv(m_id, location, sizeof(glm::vec2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec2 Program::get_uniform(GLint location)
    {
        glm::dvec2 result;
        glGetnUniformdv(m_id, location, sizeof(glm::dvec2), glm::value_ptr(result));
        return result;
    }

    //
    // vec3
    //

    template <>
    glm::ivec3 Program::get_uniform(GLint location)
    {
        glm::ivec3 result;
        glGetnUniformiv(m_id, location, sizeof(glm::ivec3), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec3 Program::get_uniform(GLint location)
    {
        glm::uvec3 result;
        glGetnUniformuiv(m_id, location, sizeof(glm::uvec3), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec3 Program::get_uniform(GLint location)
    {
        glm::vec3 result;
        glGetnUniformfv(m_id, location, sizeof(glm::vec3), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec3 Program::get_uniform(GLint location)
    {
        glm::dvec3 result;
        glGetnUniformdv(m_id, location, sizeof(glm::dvec3), glm::value_ptr(result));
        return result;
    }

    //
    // vec4
    //

    template <>
    glm::ivec4 Program::get_uniform(GLint location)
    {
        glm::ivec4 result;
        glGetnUniformiv(m_id, location, sizeof(glm::ivec4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::uvec4 Program::get_uniform(GLint location)
    {
        glm::uvec4 result;
        glGetnUniformuiv(m_id, location, sizeof(glm::uvec4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::vec4 Program::get_uniform(GLint location)
    {
        glm::vec4 result;
        glGetnUniformfv(m_id, location, sizeof(glm::vec4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::dvec4 Program::get_uniform(GLint location)
    {
        glm::dvec4 result;
        glGetnUniformdv(m_id, location, sizeof(glm::dvec4), glm::value_ptr(result));
        return result;
    }

    //
    // matrix
    //

    template <>
    glm::mat2 Program::get_uniform(GLint location)
    {
        glm::mat2 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat2x3 Program::get_uniform(GLint location)
    {
        glm::mat2x3 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat2x3), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat2x4 Program::get_uniform(GLint location)
    {
        glm::mat2x4 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat2x4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3 Program::get_uniform(GLint location)
    {
        glm::mat3 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat3), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3x2 Program::get_uniform(GLint location)
    {
        glm::mat3x2 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat3x2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat3x4 Program::get_uniform(GLint location)
    {
        glm::mat3x4 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat3x4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4 Program::get_uniform(GLint location)
    {
        glm::mat4 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat4), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4x2 Program::get_uniform(GLint location)
    {
        glm::mat4x2 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat4x2), glm::value_ptr(result));
        return result;
    }

    template <>
    glm::mat4x3 Program::get_uniform(GLint location)
    {
        glm::mat4x3 result;
        glGetnUniformfv(m_id, location, sizeof(glm::mat4x3), glm::value_ptr(result));
        return result;
    }

} // namespace gl_wrapper
