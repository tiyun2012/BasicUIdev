#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace ui
{
class Renderer;

class UIElement
{
public:
    UIElement() = default;
    virtual ~UIElement() = default;

    UIElement(const UIElement&) = delete;
    UIElement& operator=(const UIElement&) = delete;
    UIElement(UIElement&&) = default;
    UIElement& operator=(UIElement&&) = default;

    UIElement* getParent() const { return parent_; }
    const std::vector<std::unique_ptr<UIElement>>& getChildren() const { return children_; }

    void addChild(std::unique_ptr<UIElement> child);
    bool removeChild(const UIElement* child);

    virtual void update();
    virtual void draw(Renderer& renderer) const;
    virtual void layoutChildren();

    bool handleMouseMove(float mouseX, float mouseY);
    bool handleMouseDown(float mouseX, float mouseY);
    bool handleMouseUp(float mouseX, float mouseY);

    float x = 0.0f;
    float y = 0.0f;
    float width = 100.0f;
    float height = 100.0f;
    bool visible = true;
    bool enabled = true;

protected:
    virtual void drawSelf(Renderer& renderer) const;
    virtual bool onMouseMove(float mouseX, float mouseY);
    virtual bool onMouseDown(float mouseX, float mouseY);
    virtual bool onMouseUp(float mouseX, float mouseY);

    bool containsPoint(float mouseX, float mouseY) const;
    float getGlobalX() const;
    float getGlobalY() const;
    std::vector<std::unique_ptr<UIElement>>& getChildrenMutable();

private:
    UIElement* parent_ = nullptr;
    std::vector<std::unique_ptr<UIElement>> children_;
};
} // namespace ui
