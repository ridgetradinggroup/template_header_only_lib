#ifndef {{ project_name_upper }}_{{ project_name_upper }}_H
#define {{ project_name_upper }}_{{ project_name_upper }}_H

#include <string>
#include <iostream>

namespace ridge {

// Header-only implementation: Returns the classic hello world message
inline std::string get_message() {
    return "Hello, World!";
}

// Header-only implementation: Prints hello message to stdout
inline void print_message() {
    std::cout << get_message() << std::endl;
}

} // namespace ridge

#endif // {{ project_name_upper }}_{{ project_name_upper }}_H