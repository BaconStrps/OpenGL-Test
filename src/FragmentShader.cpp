#include "FragmentShader.h"

void FragmentShader::compile()
{
	type = ShaderType::FRAGMENT;
	shaderID = glCreateShader(static_cast<GLenum>(type));
	const char* p_Src = src.c_str();
	glShaderSource(shaderID, 1, &p_Src, nullptr);
	glCompileShader(shaderID);
}
