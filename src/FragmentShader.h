#pragma once
#include "Shader.h"
class FragmentShader : public Shader
{
public:
    FragmentShader(const std::filesystem::path& filepath)
    {
        Init(filepath);
    }
private:
    void compile() override;
private:
};

