#pragma once
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "FragmentShader.h"
#include "VertexShader.h"
#include "GLProgram.h"
#include <GL/glew.h>
#include <cstdint>
#include <vector>
#include <fstream>
#include <string>

class OpenGlRenderer
{
public:
	OpenGlRenderer();
	~OpenGlRenderer();

	/*
		Creates a renderer with the specified mode.
	*/
	OpenGlRenderer(GLenum _mode);
	/*
		Initializes the renderer with the specified mode.
	*/
	void Init(GLenum _mode)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		mode = _mode;
	};
	void Draw(const VertexArray& vlayout, const IndexBuffer& ibuf, const GLProgram& program) const;
private:
	uint32_t programid = 0;
	GLenum mode = 0;
};

