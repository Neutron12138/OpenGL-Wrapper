#include "program.hpp"
#include "../base/scoped_binder.hpp"

namespace gl_wrapper
{
    template <>
    inline ScopedBinder::ScopedBinder(Program *current, Program *previous)
        : m_current_binder([=]()
                           { if(current) current->use(); }),
          m_current_unbinder([=]()
                             { if(current) current->unuse(); }),
          m_previous_binder([=]()
                            { if(previous) previous->use(); }),
          m_previous_unbinder([=]()
                              { if(previous) previous->unuse(); }) { _bind(); }

    template <>
    inline ScopedBinder::ScopedBinder(Program *current, std::nullptr_t)
        : m_current_binder([=]()
                           { if(current) current->use(); }),
          m_current_unbinder([=]()
                             { if(current) current->unuse(); }) { _bind(); }

    template <>
    inline ScopedBinder::ScopedBinder(std::nullptr_t, Program *previous)
        : m_previous_binder([=]()
                            { if(previous) previous->use(); }),
          m_previous_unbinder([=]()
                              { if(previous) previous->unuse(); }) { _bind(); }

} // namespace gl_wrapper
