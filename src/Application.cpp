#include "Application.h"
#include "VertexBuffer.h"
#include "funcs.h"
#include "VertexShader.h"
#include "VertexArray.h"
#include "FragmentShader.h"
#include "Texture.h"
#include <iostream>
#include <utility>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

Application::Application(int _width, int _height) : width(_width), height(_height)
{
	Create(width, height);
	
	run();
}

Application::~Application()
{
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	if(window != nullptr)
		glfwTerminate();

}

bool Application::Create(int _width, int _height)
{

	width = _width;
	height = _height;
	

	if (glfwInit() == GLFW_FALSE)
		return false;
	window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	std::cout << glGetString(GL_VERSION) << std::endl;
	GLenum error = glewInit();

	FragmentShader fs("shaders/Frag.shader");
	VertexShader vs("shaders/Vertex.shader");

	renderer.Init(GL_TRIANGLES);

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	ImGui::StyleColorsDark();

	if (window != nullptr && error == GLEW_OK)
	{
		run();
		return true;
	}
	else
	{
		std::cout << glewGetErrorString(error) << '\n';
		return false;
	}
}

void Application::run()
{
	float widthRatio = float(width) / height;
	float heightRatio = 1 / widthRatio;

	widthRatio *= 3;
	heightRatio *= 5;

	glm::mat4 proj = glm::ortho(-widthRatio, widthRatio, -heightRatio, heightRatio, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-0.48123f, .745651f, 0.0f));

	glm::mat4 mvp = proj * view * model;
	Vertex vertices[] =
	{
		{-0.5f,	-0.5f, {1.0f, 0.0f, 0.0f, 1.0f}, {0.0f ,0.0f}},
		{ 0.5f,	-0.5f, {0.0f, 1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{ 0.5f,  0.5f, {0.0f, 0.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},
		{ -0.5f, 0.5f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
	};

	uint32_t quadindices[] =
	{
		0, 1, 2, 2, 3, 0
	};

	Texture texture("res/textures/dvd.png");
	texture.Bind(0);

	VertexBuffer vbuf(vertices, 4);
	VertexArray varray;
	varray.PushElement<float>(2);
	varray.PushElement<float>(4);
	varray.PushElement<float>(2);

	varray.BindLayout(vbuf);
	IndexBuffer ibuf(quadindices, 6);
	GLProgram prog(VertexShader("shaders/Vertex.shader"), FragmentShader("shaders/Frag.shader"));

	prog.Bind();

	prog.SetUniform1i("u_Texture", 0);
	prog.SetUniformMat4f("u_MVP", mvp);

	glm::vec3 vel(.025f, -.025f, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//{
		//	static float f = 0.0f;
		//	static int counter = 0;

		//	ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		//	ImGui::SliderFloat3("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		//	ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

		//	if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		//		counter++;
		//	ImGui::SameLine();
		//	ImGui::Text("counter = %d", counter);

		//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//	ImGui::End();
		//}


		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		model = glm::translate(model, vel);
		mvp = proj * view * model;

		prog.SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(varray, ibuf, prog);

		if (model[3].x > view[0].x * widthRatio - 0.5 || model[3].x < -view[0].x * widthRatio + 0.5)
		{
			vel.x *= -1;
		}
		if (model[3].y > view[1].y*heightRatio - 0.5|| model[3].y < -view[1].y*heightRatio + 0.5)
		{
			vel.y *= -1;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

}


