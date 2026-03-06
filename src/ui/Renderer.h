#pragma once

#include <iostream>
#include <string>

namespace ui
{
class Renderer
{
public:
    virtual ~Renderer() = default;

    virtual void drawRect(float x, float y, float width, float height, const std::string& style) = 0;
    virtual void drawText(float x, float y, const std::string& text, const std::string& style) = 0;
    virtual void drawImage(float x, float y, float width, float height, const std::string& imagePath) = 0;
};

class ConsoleRenderer final : public Renderer
{
public:
    void drawRect(float x, float y, float width, float height, const std::string& style) override
    {
        std::cout << "drawRect [" << style << "] @(" << x << ", " << y << ") size(" << width << ", " << height << ")\n";
    }

    void drawText(float x, float y, const std::string& text, const std::string& style) override
    {
        std::cout << "drawText [" << style << "] @(" << x << ", " << y << ") \"" << text << "\"\n";
    }

    void drawImage(float x, float y, float width, float height, const std::string& imagePath) override
    {
        std::cout << "drawImage \"" << imagePath << "\" @(" << x << ", " << y << ") size(" << width << ", " << height << ")\n";
    }
};
} // namespace ui
