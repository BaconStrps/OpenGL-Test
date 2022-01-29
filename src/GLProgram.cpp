#include "GLProgram.h"
#include "funcs.h"

GLProgram::GLProgram(const VertexShader& vshader, const FragmentShader& fshader) : m_ProgramID(0)
{
	m_ProgramID = glCreateProgram();
	glAttachShader(m_ProgramID, vshader.shaderID);
	glAttachShader(m_ProgramID, fshader.shaderID);
	glLinkProgram(m_ProgramID);
	ASSERT(checkErrors());
}

GLProgram::~GLProgram()
{
	glDeleteProgram(m_ProgramID);
}

void GLProgram::Bind() const
{
	glUseProgram(m_ProgramID);
}

void GLProgram::Unbind() const
{
	glUseProgram(0);
}

void GLProgram::SetUniform4f(const std::string& uname, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(uname), v0, v1, v2, v3);
}

void GLProgram::SetUniform1i(const std::string& uname, const int v0)
{
	glUniform1i(getUniformLocation(uname), v0);
}

void GLProgram::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &(matrix[0][0])));
}

int GLProgram::getUniformLocation(const std::string& uname)
{
	if (cache.find(uname) != cache.end())
	{
		return cache[uname];
	}
	else
	{
		cache.emplace(uname, glGetUniformLocation(m_ProgramID, uname.c_str()));
	}

	return cache[uname];

}
