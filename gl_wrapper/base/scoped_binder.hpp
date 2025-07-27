#pragma once

#include <utility>
#include <functional>
#include <base/misc/noncopyable_object.hpp>

namespace gl_wrapper
{
    /// @brief 在作用域内自动绑定资源
    class ScopedBinder : public base::NoncopyableObject
    {
    public:
        using BindingFunc = void();
        using Function = std::function<BindingFunc>;

    private:
        /// @brief 当前绑定器
        Function m_binder = nullptr;
        /// @brief 当前解绑器
        Function m_unbinder = nullptr;

    private:
        void _bind();
        void _unbind();

    public:
        template <typename F1, typename F2>
        ScopedBinder(F1 binder, F2 unbinder)
            : m_binder(binder), m_unbinder(unbinder) { _bind(); }
        ScopedBinder(ScopedBinder &&from);
        ~ScopedBinder();
        BASE_DELETE_COPY_FUNCTION(ScopedBinder);

    public:
        Function get_binder() const;
        Function get_unbinder() const;
    };

} // namespace gl_wrapper
