#pragma once

#include <GLFW/glfw3.h>

#include <string>

class Application {
    public:

    Application(int w, int h, std::string name);
    ~Application();

    void initApp();
    void deinitApp();

    static void run(Application appt);

    private:

    void mainLoop(Application appt);
    void getInput(GLFWwindow *pWindow);
    bool shouldClose() { return glfwWindowShouldClose(pWindow); }

    const int width;
    const int height;

    std::string windowName;

    GLFWwindow *pWindow;
};
