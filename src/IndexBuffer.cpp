#include "IndexBuffer.h"


#include "IndexBuffer.h"
IndexBuffer::IndexBuffer(const void* data, const uint32_t count) : length(count)
{
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW);
}

IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept
{
	bufferID = other.bufferID;
	other.bufferID = 0;

	length = other.length;
	other.length = 0;
}
IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

