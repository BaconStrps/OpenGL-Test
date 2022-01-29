#include "VertexArray.h"

VertexArray::VertexArray() : m_BufferID(0), stride(0)
{
	glGenVertexArrays(1, &m_BufferID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_BufferID);
}

void VertexArray::BindLayout(VertexBuffer& vb) const
{
	Bind();
	vb.Bind();
	int64_t offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, stride, (const void*)offset);

		offset += LayoutElement::GetSizeOfType(element.type) * element.count;
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
