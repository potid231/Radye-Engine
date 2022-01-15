#include "application.hpp"

#include "input/mouse.hpp"
#include "input/keyboard.hpp"

void Application::initApp() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    pWindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

void Application::deinitApp() {
    glfwDestroyWindow(pWindow);
}

Application::Application(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
    initApp();
}

Application::~Application() { glfwTerminate(); }

void Application::mainLoop(Application appt) {
    while (!appt.shouldClose()) {
        glfwPollEvents();
    }
}

void Application::getInput(GLFWwindow *pWindow) {
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

void Application::run(Application appt) {
    appt.getInput(appt.pWindow);

    appt.mainLoop(appt);
}
