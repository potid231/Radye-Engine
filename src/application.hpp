#pragma once

#include <GLFW/glfw3.h>

#include <string>

class Application {
    public:

    Application(int w, int h, std::string name);
    ~Application();

    void initApp();

    bool shouldClose() { return glfwWindowShouldClose(pWindow); }

    void mainLoop(Application appt);

    // <app name>.run(<loop for <app name>>)
    void run(Application appt);

    private:

    const int width;
    const int height;

    std::string windowName;

    GLFWwindow *pWindow;
};
