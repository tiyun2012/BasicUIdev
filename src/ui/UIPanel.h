#pragma once

#include <string>

#include "ui/UIElement.h"

namespace ui
{
enum class LayoutMode
{
    None,
    Vertical,
    Horizontal
};

class UIPanel : public UIElement
{
public:
    LayoutMode layoutMode = LayoutMode::None;
    float spacing = 8.0f;
    float padding = 8.0f;
    std::string style = "Panel";

    void layoutChildren() override;

protected:
    void drawSelf(Renderer& renderer) const override;
};
} // namespace ui
