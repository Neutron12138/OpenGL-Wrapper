#pragma once

#include "gl_loader.hpp"

namespace gl_wrapper
{
    GLLoader::GLLoader()
    {
        if (!gladLoadGL())
            throw BASE_MAKE_RUNTIME_ERROR("Unable to load OpenGL function pointers");
        check_version();
    }

    GLLoader::GLLoader(GLADloadproc proc)
    {
        if (!gladLoadGLLoader(proc))
            throw BASE_MAKE_RUNTIME_ERROR("Unable to load OpenGL function pointers",
                                          ", load proc: ", proc);
        check_version();
    }

    glm::ivec2 GLLoader::get_version() const
    {
        glm::ivec2 version;
        glGetIntegerv(GL_MAJOR_VERSION, &version.x);
        glGetIntegerv(GL_MINOR_VERSION, &version.y);
        return version;
    }

    void GLLoader::check_version() const
    {
        glm::ivec2 version = get_version();
        if (version.x == 4 && version.y >= 5)
            return;

        throw BASE_MAKE_RUNTIME_ERROR(
            "The current OpenGL context version is too low, it should be at least OpenGL 4.5");
    }

} // namespace gl_wrapper
