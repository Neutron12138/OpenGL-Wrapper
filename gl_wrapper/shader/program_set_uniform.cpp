#include <glm/gtc/type_ptr.hpp>
#include "program.hpp"

namespace gl_wrapper
{
    //
    // scalar
    //

    template <>
    void Program::set_uniform(GLint location, GLint &&value) { glProgramUniform1i(m_id, location, value); }

    template <>
    void Program::set_uniform(GLint location, GLuint &&value) { glProgramUniform1ui(m_id, location, value); }

    template <>
    void Program::set_uniform(GLint location, GLfloat &&value) { glProgramUniform1f(m_id, location, value); }

    template <>
    void Program::set_uniform(GLint location, GLdouble &&value) { glProgramUniform1d(m_id, location, value); }

    //
    // vec2
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec2 &&value) { glProgramUniform2iv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec2 &&value) { glProgramUniform2uiv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec2 &&value) { glProgramUniform2fv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec2 &&value) { glProgramUniform2dv(m_id, location, 1, glm::value_ptr(value)); }

    //
    // vec3
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec3 &&value) { glProgramUniform3iv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec3 &&value) { glProgramUniform3uiv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec3 &&value) { glProgramUniform3fv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec3 &&value) { glProgramUniform3dv(m_id, location, 1, glm::value_ptr(value)); }

    //
    // vec4
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec4 &&value) { glProgramUniform4iv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec4 &&value) { glProgramUniform4uiv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec4 &&value) { glProgramUniform4fv(m_id, location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec4 &&value) { glProgramUniform4dv(m_id, location, 1, glm::value_ptr(value)); }

    //
    // matrix
    //

    template <>
    void Program::set_uniform(GLint location, glm::mat2 &&value) { glProgramUniformMatrix2fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat2x3 &&value) { glProgramUniformMatrix2x3fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat2x4 &&value) { glProgramUniformMatrix2x4fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3 &&value) { glProgramUniformMatrix3fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3x2 &&value) { glProgramUniformMatrix3x2fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3x4 &&value) { glProgramUniformMatrix3x4fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4 &&value) { glProgramUniformMatrix4fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4x2 &&value) { glProgramUniformMatrix4x2fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4x3 &&value) { glProgramUniformMatrix4x3fv(m_id, location, 1, GL_FALSE, glm::value_ptr(value)); }

} // namespace gl_wrapper
