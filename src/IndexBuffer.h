#pragma once
#include <GL/glew.h>
#include <cstdint>
class IndexBuffer
{
public:

	IndexBuffer(const void* data, const uint32_t count);

	IndexBuffer() = default;

	IndexBuffer(IndexBuffer&& other) noexcept;

	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline uint32_t GetLength() const { return length; }

public:

	IndexBuffer& operator=(IndexBuffer&& other) noexcept
	{
		bufferID = other.bufferID;
		length = other.length;

		other.bufferID = 0;
		other.length = 0;

		return *this;
	}

private:
	uint32_t length;
	uint32_t bufferID = 0;
};

