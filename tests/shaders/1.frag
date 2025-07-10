#version 330 core

in vec3 v_col;
in vec3 v_tex;
out vec4 o_col;

uniform sampler2D u_tex;

void main()
{
    o_col = vec4(v_col, 1.0) * texture(u_tex, v_tex.st);
}
