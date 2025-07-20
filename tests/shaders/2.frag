#version 450 core

in vec2 v_uv;

out vec4 o_col;

uniform sampler2D u_texture;

void main()
{
    o_col = texture(u_texture, v_uv);
}
