#pragma once

#include <glm/glm.hpp>
#include <base/core/exception.hpp>
#include <base/core/noncopyable_object.hpp>
#include <glad/glad.h>

namespace gl_wrapper
{
    /// @brief 通过GLAD加载OpenGL函数指针的加载器
    class GLLoader : public base::NoncopyableObject
    {
    public:
        inline GLLoader()
        {
            if (!gladLoadGL())
                throw BASE_MAKE_RUNTIME_ERROR("Unable to load OpenGL function pointers");

            if (!GLAD_GL_VERSION_3_3)
                throw BASE_MAKE_RUNTIME_ERROR(
                    "The current OpenGL context version is too low, it should be at least OpenGL 3.3");
        }

        inline GLLoader(GLADloadproc proc)
        {
            if (!gladLoadGLLoader(proc))
                throw BASE_MAKE_RUNTIME_ERROR("Unable to load OpenGL function pointers",
                                              ", load proc: ", proc);

            if (!GLAD_GL_VERSION_3_3)
                throw BASE_MAKE_RUNTIME_ERROR(
                    "The current OpenGL context version is too low, it should be at least OpenGL 3.3");
        }

        inline ~GLLoader() = default;
    };

} // namespace gl_wrapper
