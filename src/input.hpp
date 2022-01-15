#pragma once

#include <GLFW/glfw3.h>

#include "input/mouse.hpp"
#include "input/keyboard.hpp"

void getInput(GLFWwindow *pWindow) {
    // Mouse
    glfwSetCursorPosCallback(pWindow, positionCallBack);
    glfwSetCursorEnterCallback(pWindow, cursorEnterCallBack);
    glfwSetScrollCallback(pWindow, scrollCallBack);
    glfwSetMouseButtonCallback(pWindow, buttonCallBack);
    // Mouse

    // Keyboard
    glfwSetKeyCallback(pWindow, keyCallBack);
    glfwSetCharCallback(pWindow, charCallBack);
    // Keyboard

    // Cursor
    glfwSetCursorPosCallback(pWindow, positionCallBack);
    glfwSetCursorEnterCallback(pWindow, cursorEnterCallBack);
    glfwSetScrollCallback(pWindow, scrollCallBack);
    glfwSetMouseButtonCallback(pWindow, buttonCallBack);
    // Cursor

    // Keyboard
    glfwSetKeyCallback(pWindow, keyCallBack);
    glfwSetCharCallback(pWindow, charCallBack);
    // Keyboard
}
