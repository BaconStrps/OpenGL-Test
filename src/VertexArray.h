#pragma once
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <vector>
#include <cstdint>

struct LayoutElement
{
	uint32_t type;
	uint32_t count;
	uint8_t normalized;

	static uint32_t GetSizeOfType(const uint32_t type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}
		return 0;
	}
};


class VertexArray
{
public:

	VertexArray();
	~VertexArray();

	const uint32_t GetStride() const { return stride; }
	const std::vector<LayoutElement>& GetElements() const { return elements; }
	void BindLayout(VertexBuffer& vb) const;
	void Bind() const;
	void Unbind() const;



public:
	template<typename T>
	void PushElement(uint32_t count)
	{
		static_assert(false); //oopsies dunno what to do here
	}

	template<>
	void PushElement<float>(uint32_t count)
	{
		elements.push_back({ GL_FLOAT, count, false });
		stride += sizeof(float) * count;
	}

	template<>
	void PushElement<uint32_t>(uint32_t count)
	{
		elements.push_back({ GL_UNSIGNED_INT, count, false });
		stride += sizeof(uint32_t) * count;
	}

private:
	uint32_t m_BufferID;
	uint32_t stride;
	std::vector<LayoutElement> elements;
};

