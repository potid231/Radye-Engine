#include "application.hpp"

#include "input.hpp"

void Application::initApp() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    pWindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

Application::Application(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
    initApp();
}

Application::~Application() {
    glfwDestroyWindow(pWindow);
    glfwTerminate();
}

void Application::mainLoop(Application appt) {
    while (!appt.shouldClose()) {
        glfwPollEvents();
    }
}

void Application::run(Application appt) {

    getInput(pWindow);

    mainLoop(appt);

}
