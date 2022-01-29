#include "OpenGlRenderer.h"
#include "funcs.h"
#include <stdexcept>
OpenGlRenderer::OpenGlRenderer()
{
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
}
OpenGlRenderer::~OpenGlRenderer()
{
}
OpenGlRenderer::OpenGlRenderer(GLenum _mode) : mode(_mode)
{
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
}
void OpenGlRenderer::Draw(const VertexArray& vlayout, const IndexBuffer& ibuf, const GLProgram& program) const
{
	vlayout.Bind();
	ibuf.Bind();
	program.Bind();
	GLCall(glDrawElements(mode, ibuf.GetLength(), GL_UNSIGNED_INT, nullptr)); // assume triangle for now
}