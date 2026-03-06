#pragma once

#include "ui/UIElement.h"

namespace ui
{
class Renderer;

class UIManager
{
public:
    UIElement root;

    void update();
    void draw(Renderer& renderer) const;

    bool onMouseMove(float mouseX, float mouseY);
    bool onMouseDown(float mouseX, float mouseY);
    bool onMouseUp(float mouseX, float mouseY);
};
} // namespace ui
