#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 v_Color;
layout(location = 2) in vec2 texCoord;
out vec4 color;
out vec2 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
	v_TexCoord = texCoord;
	color = v_Color;
	gl_Position = u_MVP * position;
}