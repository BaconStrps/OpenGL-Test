#pragma once
#include <cstdint>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define ASSERT(x) if(!(x)) __debugbreak();
#ifdef _DEBUG
#define GLCall(x) clearErrors();\
			x;\
			ASSERT(checkErrors())
#else
#define GLCall(x) x;
#endif


enum class ChangeDirection{UP, DOWN, LEFT, RIGHT};


void checkBoundary(glm::mat4& view, glm::mat4& proj);

bool checkErrors();
void clearErrors();