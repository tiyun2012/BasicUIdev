#pragma once

#include <functional>
#include <string>

#include "ui/UIElement.h"

namespace ui
{
class UIButton : public UIElement
{
public:
    explicit UIButton(std::string label = "");

    std::string text;
    std::function<void()> onClick;

protected:
    void drawSelf(Renderer& renderer) const override;
    bool onMouseMove(float mouseX, float mouseY) override;
    bool onMouseDown(float mouseX, float mouseY) override;
    bool onMouseUp(float mouseX, float mouseY) override;

private:
    bool hovered_ = false;
    bool pressed_ = false;
};
} // namespace ui
