#pragma once

#include <glm/gtc/type_ptr.hpp>
#include "program.hpp"

namespace gl_wrapper
{
    void Program::get_uniform(GLint location, GLint &result) const { glGetnUniformiv(m_id, location, sizeof(result), &result); }
    void Program::get_uniform(GLint location, GLuint &result) const { glGetnUniformuiv(m_id, location, sizeof(result), &result); }
    void Program::get_uniform(GLint location, GLfloat &result) const { glGetnUniformfv(m_id, location, sizeof(result), &result); }
    void Program::get_uniform(GLint location, GLdouble &result) const { glGetnUniformdv(m_id, location, sizeof(result), &result); }

    void Program::get_uniform(GLint location, glm::ivec2 &result) const { glGetnUniformiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::uvec2 &result) const { glGetnUniformuiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::vec2 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::dvec2 &result) const { glGetnUniformdv(m_id, location, sizeof(result), glm::value_ptr(result)); }

    void Program::get_uniform(GLint location, glm::ivec3 &result) const { glGetnUniformiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::uvec3 &result) const { glGetnUniformuiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::vec3 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::dvec3 &result) const { glGetnUniformdv(m_id, location, sizeof(result), glm::value_ptr(result)); }

    void Program::get_uniform(GLint location, glm::ivec4 &result) const { glGetnUniformiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::uvec4 &result) const { glGetnUniformuiv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::vec4 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::dvec4 &result) const { glGetnUniformdv(m_id, location, sizeof(result), glm::value_ptr(result)); }

    void Program::get_uniform(GLint location, glm::mat2 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat2x3 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat2x4 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat3 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat3x2 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat3x4 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat4 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat4x2 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }
    void Program::get_uniform(GLint location, glm::mat4x3 &result) const { glGetnUniformfv(m_id, location, sizeof(result), glm::value_ptr(result)); }

} // namespace gl_wrapper
