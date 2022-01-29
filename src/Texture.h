#pragma once

#include "OpenGlRenderer.h"
#include <filesystem>

class Texture
{
public:

	Texture(const std::filesystem::path& path);
	~Texture();

	void Bind(const uint32_t slot) const;
	void Unbind() const;

	inline uint32_t GetWidth() const { return m_Width; }
	inline uint32_t GetHeight() const { return m_Height; }

private:
	uint32_t m_TextureID;
	std::filesystem::path m_FilePath;
	uint8_t* m_LocalBuffer;
	int32_t m_Width, m_Height, m_BPP;
};

