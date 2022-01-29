#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "OpenGlRenderer.h"
class Application
{
public:
	/*
		Create a blank application.
		Use the Create() method to create the window.
	*/
	Application() {};
	/*
		int width, int height
		Create a new window with the specified dimensions.
	*/
	Application(int, int); 
	/*
		Releases all resources.
	*/
	~Application();

	/*
		int width, int height
		Create a new window.
	*/
	bool Create(int _width, int _height);

private:

	void run();


private:
	uint32_t width = 0, height = 0;
	OpenGlRenderer renderer;
	GLFWwindow* window = nullptr;

};

