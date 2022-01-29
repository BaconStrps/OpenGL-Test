#pragma once
#include <GL/glew.h>
#include <cstdint>

/*
	Struct to manage actual data?
	Class needs to contain info about the data
	Needs to be *fast*
	Needs to be extendable
*/


struct Vertex
{
	float x, y; //2d for now ig
	float color[4];
	float texcoords[2];
	//extend this later when needed
};

class VertexBuffer
{
public:

	VertexBuffer(const void* vertices, uint32_t length);

	VertexBuffer() = default;

	VertexBuffer(VertexBuffer&& other) noexcept;

	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

public:

	VertexBuffer& operator=(VertexBuffer&& other) noexcept
	{
		bufferID = other.bufferID;
		other.bufferID = 0;

		return *this;
	}

private:
	uint32_t bufferID = 0;
};

