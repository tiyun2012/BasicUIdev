cmake_minimum_required(VERSION 3.16)
project(BasicUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BasicUI
    src/main.cpp
    src/ui/UIElement.cpp
    src/ui/UIManager.cpp
    src/ui/UIPanel.cpp
    src/ui/UIButton.cpp
    src/ui/UIText.cpp
    src/ui/UIImage.cpp
)

target_include_directories(BasicUI PRIVATE src)
