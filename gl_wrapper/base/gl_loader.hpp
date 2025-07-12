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
            check_version();
        }
        inline GLLoader(GLADloadproc proc)
        {
            if (!gladLoadGLLoader(proc))
                throw BASE_MAKE_RUNTIME_ERROR("Unable to load OpenGL function pointers",
                                              ", load proc: ", proc);
            check_version();
        }
        inline ~GLLoader() = default;

    public:
        glm::ivec2 get_version() const
        {
            glm::ivec2 version;
            glGetIntegerv(GL_MAJOR_VERSION, &version.x);
            glGetIntegerv(GL_MINOR_VERSION, &version.y);
            return version;
        }

        void check_version() const
        {
            glm::ivec2 version = get_version();
            if (version.x == 4 || (version.x == 3 && version.y >= 3))
                return;

            throw BASE_MAKE_RUNTIME_ERROR(
                "The current OpenGL context version is too low, it should be at least OpenGL 3.3");
        }
    };

} // namespace gl_wrapper
