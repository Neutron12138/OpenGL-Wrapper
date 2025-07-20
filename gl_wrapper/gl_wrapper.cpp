#pragma once

// base

#ifdef GL_WRAPPER_INCLUDE_GLAD_IMPL
#include <glad/glad.c>
#endif

#include "base/gl_loader.cpp"
#include "base/resource.cpp"
#include "base/debug_message_callback.cpp"
#include "base/scoped_binder.cpp"

// state

#include "state/viewport_state.cpp"
#include "state/depth_test_state.cpp"
#include "state/clear_state.cpp"
#include "state/cull_face_state.cpp"
#include "state/blend_state.cpp"
#include "state/scissor_test_state.cpp"
#include "state/stencil_test_state.cpp"

// buffer

#include "buffer/buffer.cpp"
#include "buffer/vertex_buffer.cpp"
#include "buffer/element_buffer.cpp"

// vertex array

#include "vertex_array/vertex_array.cpp"
#include "vertex_array/vertex_array_set_attrib_format.cpp"

// shader

#include "shader/shader.cpp"
#include "shader/program.cpp"
#include "shader/program_set_uniform.cpp"
#include "shader/program_get_uniform.cpp"

// texture

#include "texture/texture.cpp"
#include "texture/texture_2d.cpp"
#include "texture/texture_cube_map.cpp"

// framebuffer

#include "framebuffer/renderbuffer.cpp"
#include "framebuffer/framebuffer.cpp"

// query

#include "query/query.cpp"
