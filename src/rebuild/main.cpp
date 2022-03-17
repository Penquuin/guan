#include <iostream>

#include "application.hpp"

int main() {
    reb::Application app;
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    std::cout << "HIIII" << std::endl;
    return EXIT_SUCCESS;
}