#include "ui/UIElement.h"

#include "ui/Renderer.h"

namespace ui
{
void UIElement::addChild(std::unique_ptr<UIElement> child)
{
    if (!child)
    {
        return;
    }

    child->parent_ = this;
    children_.push_back(std::move(child));
}

bool UIElement::removeChild(const UIElement* child)
{
    const auto it = std::find_if(children_.begin(), children_.end(), [child](const std::unique_ptr<UIElement>& candidate) {
        return candidate.get() == child;
    });

    if (it == children_.end())
    {
        return false;
    }

    (*it)->parent_ = nullptr;
    children_.erase(it);
    return true;
}

void UIElement::update()
{
    layoutChildren();
    for (const auto& child : children_)
    {
        child->update();
    }
}

void UIElement::draw(Renderer& renderer) const
{
    if (!visible)
    {
        return;
    }

    drawSelf(renderer);
    for (const auto& child : children_)
    {
        child->draw(renderer);
    }
}

void UIElement::layoutChildren()
{
}

bool UIElement::handleMouseMove(float mouseX, float mouseY)
{
    if (!visible || !enabled)
    {
        return false;
    }

    for (auto it = children_.rbegin(); it != children_.rend(); ++it)
    {
        if ((*it)->handleMouseMove(mouseX, mouseY))
        {
            return true;
        }
    }

    if (!containsPoint(mouseX, mouseY))
    {
        return false;
    }

    return onMouseMove(mouseX, mouseY);
}

bool UIElement::handleMouseDown(float mouseX, float mouseY)
{
    if (!visible || !enabled)
    {
        return false;
    }

    for (auto it = children_.rbegin(); it != children_.rend(); ++it)
    {
        if ((*it)->handleMouseDown(mouseX, mouseY))
        {
            return true;
        }
    }

    if (!containsPoint(mouseX, mouseY))
    {
        return false;
    }

    return onMouseDown(mouseX, mouseY);
}

bool UIElement::handleMouseUp(float mouseX, float mouseY)
{
    if (!visible || !enabled)
    {
        return false;
    }

    for (auto it = children_.rbegin(); it != children_.rend(); ++it)
    {
        if ((*it)->handleMouseUp(mouseX, mouseY))
        {
            return true;
        }
    }

    if (!containsPoint(mouseX, mouseY))
    {
        return false;
    }

    return onMouseUp(mouseX, mouseY);
}

void UIElement::drawSelf(Renderer& renderer) const
{
    renderer.drawRect(getGlobalX(), getGlobalY(), width, height, "UIElement");
}

bool UIElement::onMouseMove(float, float)
{
    return false;
}

bool UIElement::onMouseDown(float, float)
{
    return false;
}

bool UIElement::onMouseUp(float, float)
{
    return false;
}

bool UIElement::containsPoint(float mouseX, float mouseY) const
{
    const float gx = getGlobalX();
    const float gy = getGlobalY();
    const bool withinX = mouseX >= gx && mouseX <= gx + width;
    const bool withinY = mouseY >= gy && mouseY <= gy + height;
    return withinX && withinY;
}

float UIElement::getGlobalX() const
{
    return parent_ ? parent_->getGlobalX() + x : x;
}

float UIElement::getGlobalY() const
{
    return parent_ ? parent_->getGlobalY() + y : y;
}

std::vector<std::unique_ptr<UIElement>>& UIElement::getChildrenMutable()
{
    return children_;
}
} // namespace ui
