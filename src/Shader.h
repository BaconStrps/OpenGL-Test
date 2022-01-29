#pragma once
#include <string>
#include <utility>
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <filesystem>
enum class ShaderType{VERTEX = GL_VERTEX_SHADER, FRAGMENT = GL_FRAGMENT_SHADER, EMPTY};

class Shader
{
public:

	Shader() = default;

	void Init(const std::filesystem::path& filepath) 
	{ 
		file.open(filepath);
		getSource();
		compile(); 
		file.close();
	};

	bool checkShader()
	{
		int32_t result;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int32_t length;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);

			char* message = (char*)_malloca(length * sizeof(char));

			glGetShaderInfoLog(shaderID, length, &length, message);
			std::cout << "Shader Compiler error: \n";
			std::cout << message << std::endl;

			glDeleteShader(shaderID);

			return false;
		}
		return true;
	}
public:
	uint32_t shaderID = 0;
protected:
	virtual void compile() = 0;
	void getSource()
	{
		std::string temp;
		while (getline(file, temp))
		{
			src.append(temp + '\n');
		}
	}
protected:
	std::ifstream file;
	std::string src;
	ShaderType type = ShaderType::EMPTY;

};

