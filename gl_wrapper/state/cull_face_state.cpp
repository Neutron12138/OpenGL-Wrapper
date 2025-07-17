#pragma once

#include "cull_face_state.hpp"

namespace gl_wrapper
{
    CullFaceState::CullFaceState(GLboolean enabled, FrontFace front, CullFace cull)
        : is_cull_face_enabled(enabled), front_face(front), cull_face(cull) {}

    void CullFaceState::operator()() const
    {
        if (!is_cull_face_enabled)
        {
            glDisable(GL_CULL_FACE);
            return;
        }

        glEnable(GL_CULL_FACE);
        glFrontFace(static_cast<GLenum>(front_face));
        glCullFace(static_cast<GLenum>(cull_face));
    }

} // namespace gl_wrapper
