#include "VertexShader.h"

void VertexShader::compile()
{
	type = ShaderType::VERTEX;
	shaderID = glCreateShader((GLenum)type);
	const char* p_Src = src.c_str();
	glShaderSource(shaderID, 1, &p_Src, nullptr);
	glCompileShader(shaderID);
}
