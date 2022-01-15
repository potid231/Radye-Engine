#include <iostream>

#include "application.hpp"

#include <cstdlib>
#include <stdexcept>

int main() {
    Application editor{800, 600, "Editor"};

    try {
        Application::run(editor);
    } catch (std::exception &e) {
        editor.deinitApp();
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    editor.deinitApp();

    return EXIT_SUCCESS;
}
