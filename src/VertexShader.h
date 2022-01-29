#pragma once
#include "Shader.h"
class VertexShader : public Shader
{
public:
    VertexShader(const std::filesystem::path& filepath)
    {
        Init(filepath);
    }
private:
    void compile() override;
private:
};

