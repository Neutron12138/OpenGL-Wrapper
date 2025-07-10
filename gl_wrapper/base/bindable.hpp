#pragma once

#include "gl_resource.hpp"

namespace gl_wrapper
{
    /// @brief 可以绑定的资源
    class Bindable : public GLResource
    {
    protected:
        inline Bindable() = default;

    public:
        inline Bindable(Bindable &&from) : GLResource(std::move(from)) {}
        inline ~Bindable() override = default;

    public:
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    };

} // namespace gl_wrapper
