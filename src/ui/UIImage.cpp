#include "ui/UIImage.h"

#include <utility>

#include "ui/Renderer.h"

namespace ui
{
UIImage::UIImage(std::string source) : imagePath(std::move(source))
{
    width = 128.0f;
    height = 128.0f;
}

void UIImage::drawSelf(Renderer& renderer) const
{
    renderer.drawImage(getGlobalX(), getGlobalY(), width, height, imagePath);
}
} // namespace ui
