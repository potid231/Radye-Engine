#include <iostream>

#include "application.hpp"

#include <cstdlib>
#include <stdexcept>

int main() {
    Application editor{800, 600, "Editor"};
    try {
        editor.run(editor);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
