#include <iostream>
#include <memory>

#include "ui/Renderer.h"
#include "ui/UIButton.h"
#include "ui/UIImage.h"
#include "ui/UIManager.h"
#include "ui/UIPanel.h"
#include "ui/UIText.h"

int main()
{
    ui::UIManager uiManager;
    ui::ConsoleRenderer renderer;

    uiManager.root.width = 1280.0f;
    uiManager.root.height = 720.0f;

    auto panel = std::make_unique<ui::UIPanel>();
    panel->x = 24.0f;
    panel->y = 24.0f;
    panel->width = 320.0f;
    panel->height = 180.0f;
    panel->layoutMode = ui::LayoutMode::Vertical;
    panel->style = "MainPanel";

    auto button = std::make_unique<ui::UIButton>("Play");
    button->onClick = []() {
        std::cout << "Button clicked\n";
    };

    auto label = std::make_unique<ui::UIText>("Status: Ready");
    label->height = 24.0f;

    panel->addChild(std::move(button));
    panel->addChild(std::move(label));

    auto image = std::make_unique<ui::UIImage>("assets/logo.png");
    image->x = 400.0f;
    image->y = 24.0f;
    image->width = 256.0f;
    image->height = 128.0f;

    uiManager.root.addChild(std::move(panel));
    uiManager.root.addChild(std::move(image));

    uiManager.update();

    std::cout << "=== draw ===\n";
    uiManager.draw(renderer);

    std::cout << "=== input ===\n";
    uiManager.onMouseMove(40.0f, 40.0f);
    uiManager.onMouseDown(40.0f, 40.0f);
    uiManager.onMouseUp(40.0f, 40.0f);

    return 0;
}
