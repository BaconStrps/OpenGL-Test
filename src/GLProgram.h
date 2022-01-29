#pragma once
#include "VertexShader.h"
#include "FragmentShader.h"
#include <cstdint>
#include <unordered_map>
#include <glm/glm.hpp>
class GLProgram
{
public:
	GLProgram() = default;

	GLProgram(const VertexShader& vshader, const FragmentShader& fshader);

	~GLProgram();

	void Bind() const;
	void Unbind() const;


	void SetUniform4f(const std::string& uname, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& uname, const int v0);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
	int getUniformLocation(const std::string& uname);

private:
	uint32_t m_ProgramID;
	std::unordered_map<std::string, int> cache;
};

