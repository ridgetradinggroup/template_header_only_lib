#include "{{ project_name_underscore }}.h"

int main() {
    // Demonstrate usage of header-only library
    ridge::print_message();

    // Additional usage example
    auto message = ridge::get_message();
    std::cout << "Retrieved message: " << message << std::endl;

    return 0;
}