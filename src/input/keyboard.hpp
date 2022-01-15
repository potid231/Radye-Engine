#pragma once

// std
#include <iostream>
#include <set>

// Keyboard
struct Keyboard {
    uint32_t unicodeChar;

    // Only the last key can be repeated
    uint32_t repeatKey;

    std::set<uint32_t> pressedKeys;
    std::set<uint32_t> releasedKeys;
    std::set<uint32_t> heldKeys;

    void preProcessing() {
        unicodeChar = 0;

        repeatKey = 0;

        pressedKeys.clear();
        releasedKeys.clear();
    }
} keyboard;

void keyCallBack(GLFWwindow *pWindow, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyboard.pressedKeys.insert(key);
        keyboard.heldKeys.insert(key);
    } else if (action == GLFW_REPEAT) {
        keyboard.repeatKey = key;
    } else if (action == GLFW_RELEASE) {
        keyboard.releasedKeys.insert(key);
        keyboard.heldKeys.erase(key);
    }
}

void charCallBack(GLFWwindow *pWindow, unsigned int codepoint) { keyboard.unicodeChar = codepoint; }
