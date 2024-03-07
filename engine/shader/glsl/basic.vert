#version 410 core

layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_normal;
layout (location = 2) in vec2 v_texcoord;

layout (location = 0) out vec3 normal;
layout (location = 1) out vec2 texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float u_time;

void main() {
    vec3 pos = v_position;

    gl_Position = projection * view * model * vec4(pos, 1.0);

    normal = v_normal;
    texcoord = v_texcoord;
}
