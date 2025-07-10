#pragma once

#include <base/version.hpp>

// base

#include <glad/glad.h>
#include "base/gl_loader.hpp"
#include "base/gl_resource.hpp"
#include "base/debug_message_callback.hpp"
#include "base/scoped_binder.hpp"

#include <glad/glad.c>

// state

#include "state/scoped_state.hpp"
#include "state/viewport_state.hpp"
#include "state/depth_test_state.hpp"
#include "state/clear_state.hpp"
#include "state/cull_face_state.hpp"
#include "state/blend_state.hpp"
#include "state/scissor_test_state.hpp"
#include "state/stencil_test_state.hpp"

// buffer

#include "buffer/buffer.hpp"

#include "buffer/buffer.cpp"

// vertex array

#include "vertex_array/vertex_array.hpp"

#include "vertex_array/vertex_array.cpp"

// shader

#include "shader/shader.hpp"
#include "shader/program.hpp"

#include "shader/shader.cpp"
#include "shader/program.cpp"
#include "shader/program_scoped_binder.cpp"
#include "shader/program_set_uniform.cpp"
#include "shader/program_get_uniform.cpp"

// texture

#include "texture/texture.hpp"
#include "texture/texture_2d.hpp"

#include "texture/texture.cpp"

// framebuffer

#include "framebuffer/renderbuffer.hpp"
#include "framebuffer/framebuffer.hpp"

#include "framebuffer/renderbuffer.cpp"
#include "framebuffer/framebuffer.cpp"
