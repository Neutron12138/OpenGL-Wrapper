#pragma once

#include <base/version.hpp>

// base

#include <glad/glad.h>
#include "base/gl_loader.hpp"
#include "base/resource.hpp"
#include "base/debug_message_callback.hpp"
#include "base/scoped_binder.hpp"

// state

#include "state/viewport_state.hpp"
#include "state/depth_test_state.hpp"
#include "state/clear_state.hpp"
#include "state/cull_face_state.hpp"
#include "state/blend_state.hpp"
#include "state/scissor_test_state.hpp"
#include "state/stencil_test_state.hpp"

// buffer

#include "buffer/buffer.hpp"
#include "buffer/vertex_buffer.hpp"
#include "buffer/element_buffer.hpp"

// vertex

#include "vertex/vertex_attrib.hpp"
#include "vertex/vertex_layout.hpp"
#include "vertex/vertex_2d.hpp"
#include "vertex/vertex_2d_tex.hpp"
#include "vertex/vertex_3d.hpp"
#include "vertex/vertex_3d_tex.hpp"
#include "vertex/vertex_3d_norm.hpp"
#include "vertex/vertex_3d_tex_norm.hpp"

// vertex array

#include "vertex_array/vertex_array.hpp"
#include "vertex_array/create_vertex_array.hpp"

// shader

#include "shader/shader.hpp"
#include "shader/program.hpp"

// sampler

#include "sampler/sampler.hpp"

// texture

#include "texture/texture.hpp"
#include "texture/texture_2d.hpp"
#include "texture/texture_cube_map.hpp"

// framebuffer

#include "framebuffer/renderbuffer.hpp"
#include "framebuffer/framebuffer.hpp"

// query

#include "query/query.hpp"
