#include <glm/gtc/type_ptr.hpp>
#include "program.hpp"

namespace gl_wrapper
{
    //
    // scalar
    //

    template <>
    void Program::set_uniform(GLint location, GLint &&value) { glUniform1i(location, value); }

    template <>
    void Program::set_uniform(GLint location, GLuint &&value) { glUniform1ui(location, value); }

    template <>
    void Program::set_uniform(GLint location, GLfloat &&value) { glUniform1f(location, value); }

    template <>
    void Program::set_uniform(GLint location, GLdouble &&value) { glUniform1d(location, value); }

    //
    // vec2
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec2 &&value) { glUniform2iv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec2 &&value) { glUniform2uiv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec2 &&value) { glUniform2fv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec2 &&value) { glUniform2dv(location, 1, glm::value_ptr(value)); }

    //
    // vec3
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec3 &&value) { glUniform3iv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec3 &&value) { glUniform3uiv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec3 &&value) { glUniform3fv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec3 &&value) { glUniform3dv(location, 1, glm::value_ptr(value)); }

    //
    // vec4
    //

    template <>
    void Program::set_uniform(GLint location, glm::ivec4 &&value) { glUniform4iv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::uvec4 &&value) { glUniform4uiv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::vec4 &&value) { glUniform4fv(location, 1, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::dvec4 &&value) { glUniform4dv(location, 1, glm::value_ptr(value)); }

    //
    // matrix
    //

    template <>
    void Program::set_uniform(GLint location, glm::mat2 &&value) { glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat2x3 &&value) { glUniformMatrix2x3fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat2x4 &&value) { glUniformMatrix2x4fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3 &&value) { glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3x2 &&value) { glUniformMatrix3x2fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat3x4 &&value) { glUniformMatrix3x4fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4 &&value) { glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4x2 &&value) { glUniformMatrix4x2fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

    template <>
    void Program::set_uniform(GLint location, glm::mat4x3 &&value) { glUniformMatrix4x3fv(location, 1, GL_FALSE, glm::value_ptr(value)); }

} // namespace gl_wrapper
