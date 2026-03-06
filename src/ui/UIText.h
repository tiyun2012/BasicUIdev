#pragma once

#include <string>

#include "ui/UIElement.h"

namespace ui
{
class UIText : public UIElement
{
public:
    explicit UIText(std::string value = "");

    std::string text;
    std::string style = "Text";

protected:
    void drawSelf(Renderer& renderer) const override;
};
} // namespace ui
