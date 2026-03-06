#include "ui/UIButton.h"

#include <utility>

#include "ui/Renderer.h"

namespace ui
{
UIButton::UIButton(std::string label) : text(std::move(label))
{
    width = 140.0f;
    height = 36.0f;
}

void UIButton::drawSelf(Renderer& renderer) const
{
    const std::string style = pressed_ ? "ButtonPressed" : (hovered_ ? "ButtonHover" : "Button");
    renderer.drawRect(getGlobalX(), getGlobalY(), width, height, style);
    renderer.drawText(getGlobalX() + 10.0f, getGlobalY() + 22.0f, text, "ButtonText");
}

bool UIButton::onMouseMove(float, float)
{
    hovered_ = true;
    return true;
}

bool UIButton::onMouseDown(float, float)
{
    pressed_ = true;
    return true;
}

bool UIButton::onMouseUp(float, float)
{
    if (pressed_)
    {
        pressed_ = false;
        if (onClick)
        {
            onClick();
        }
    }
    return true;
}
} // namespace ui
