#include "ui/UIText.h"

#include <utility>

#include "ui/Renderer.h"

namespace ui
{
UIText::UIText(std::string value) : text(std::move(value))
{
    width = 200.0f;
    height = 24.0f;
}

void UIText::drawSelf(Renderer& renderer) const
{
    renderer.drawText(getGlobalX(), getGlobalY() + 18.0f, text, style);
}
} // namespace ui
