#pragma once

// std
#include <iostream>
#include <set>

// Mouse
struct Mouse {
    struct Vec2 {
        double x;
        double y;
    };

    bool inWindow;
    bool oldInWindow;

    Vec2 position;
    Vec2 oldPosition;

    Vec2 scroll;

    std::set<uint32_t> pressedButtons{};
    std::set<uint32_t> releasedButtons{};
    std::set<uint32_t> heldButtons{};

    void preProcessing() {
        oldInWindow = inWindow;
        oldPosition = position;

        scroll = {0, 0};

        pressedButtons.clear();
        releasedButtons.clear();
    }

    void postProcessing() {}

} mouse;

void positionCallBack(GLFWwindow *edWindow, double xPos, double yPos) {
    mouse.position = {xPos, yPos};
}

void cursorEnterCallBack(GLFWwindow *edWindow, int entered) { mouse.inWindow = entered; }

void scrollCallBack(GLFWwindow *edWindow, double xOffset, double yOffset) {
    mouse.scroll = {xOffset, yOffset};
}

void buttonCallBack(GLFWwindow *edWindow, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        mouse.pressedButtons.insert(button);
        mouse.heldButtons.insert(button);
    } else if (action == GLFW_RELEASE) {
        mouse.releasedButtons.insert(button);
        mouse.heldButtons.erase(button);
    }
}
