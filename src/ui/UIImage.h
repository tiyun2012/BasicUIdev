#pragma once

#include <string>

#include "ui/UIElement.h"

namespace ui
{
class UIImage : public UIElement
{
public:
    explicit UIImage(std::string source = "");

    std::string imagePath;

protected:
    void drawSelf(Renderer& renderer) const override;
};
} // namespace ui
