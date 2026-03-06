#include "ui/UIPanel.h"

#include "ui/Renderer.h"

namespace ui
{
void UIPanel::layoutChildren()
{
    if (layoutMode == LayoutMode::None)
    {
        return;
    }

    auto& children = getChildrenMutable();
    float cursor = padding;

    for (auto& child : children)
    {
        if (!child)
        {
            continue;
        }

        if (layoutMode == LayoutMode::Vertical)
        {
            child->x = padding;
            child->y = cursor;
            cursor += child->height + spacing;
        }
        else if (layoutMode == LayoutMode::Horizontal)
        {
            child->x = cursor;
            child->y = padding;
            cursor += child->width + spacing;
        }
    }
}

void UIPanel::drawSelf(Renderer& renderer) const
{
    renderer.drawRect(getGlobalX(), getGlobalY(), width, height, style);
}
} // namespace ui
