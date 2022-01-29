#include "funcs.h"
#include <iostream>

bool checkErrors()
{
	while (GLenum error = glGetError())
	{
		std::cout << "OpenGlError: " << error << '\n';
		return false;
	}
	return true;
}

void clearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}