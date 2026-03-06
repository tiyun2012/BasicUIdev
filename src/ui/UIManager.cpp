#include "ui/UIManager.h"

#include "ui/Renderer.h"

namespace ui
{
void UIManager::update()
{
    root.update();
}

void UIManager::draw(Renderer& renderer) const
{
    root.draw(renderer);
}

bool UIManager::onMouseMove(float mouseX, float mouseY)
{
    return root.handleMouseMove(mouseX, mouseY);
}

bool UIManager::onMouseDown(float mouseX, float mouseY)
{
    return root.handleMouseDown(mouseX, mouseY);
}

bool UIManager::onMouseUp(float mouseX, float mouseY)
{
    return root.handleMouseUp(mouseX, mouseY);
}
} // namespace ui
