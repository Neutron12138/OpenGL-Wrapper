#pragma once

#include <glm/glm.hpp>
#include <base/core/exception.hpp>
#include <base/misc/noncopyable_object.hpp>
#include <glad/glad.h>

namespace gl_wrapper
{
    /// @brief 通过GLAD加载OpenGL函数指针的加载器
    class GLLoader : public base::NoncopyableObject
    {
    public:
        GLLoader();
        GLLoader(GLADloadproc proc);
        ~GLLoader() = default;
        BASE_DELETE_COPY_FUNCTION(GLLoader);

    public:
        glm::ivec2 get_version() const;
        void check_version() const;
    };

} // namespace gl_wrapper
