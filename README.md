# {{ project_name }}

{{ project_name }} is a high-performance C++{{ cpp_standard }} header-only library generated using the Ridge C++ Generator.

## 🚀 Quick Start

### Prerequisites

- CMake 3.16+
- Ninja build system
- C++{{ cpp_standard }} capable compiler (GCC 13+, Clang 17+)
- vcpkg (for dependency management)

### Building and Using the Header-Only Library

Since this is a header-only library, there's no separate compilation step required. Simply include the headers in your project.

```bash
# Set vcpkg environment
export VCPKG_ROOT=/path/to/vcpkg

# Debug build (with tests)
cmake --preset debug
cmake --build --preset debug

# Run tests
ctest --preset debug --verbose

# Release build (optimized)
cmake --preset release-g++
cmake --build --preset release-g++
```

### Using {{ project_name }} in Your Project

#### Option 1: As an Installed Package

```bash
# Install the library
cmake --preset release-g++
cmake --build --preset release-g++ --target install
```

Then in your CMakeLists.txt:
```cmake
find_package({{ project_name_underscore }} REQUIRED)
target_link_libraries(your_target PRIVATE {{ namespace_scope }}::{{ project_name_underscore }})
```

#### Option 2: As a Subdirectory

```cmake
# Add as subdirectory
add_subdirectory(path/to/{{ project_name }})
target_link_libraries(your_target PRIVATE {{ namespace_scope }}::{{ project_name_underscore }})
```

#### Option 3: Direct Header Inclusion

```cpp
#include "{{ project_name_underscore }}.h"

int main() {
    // Use the header-only functions directly
    ridge::print_message();
    auto message = ridge::get_message();
    return 0;
}
```

## 📚 Library Usage

This header-only library provides the following functions in the `ridge` namespace:

```cpp
#include "{{ project_name_underscore }}.h"

// Get a greeting message
std::string message = ridge::get_message();

// Print message to stdout
ridge::print_message();
```

## 🏗️ Build Presets

| Preset | Compiler | Use Case |
|--------|----------|----------|
| `debug` | GCC | Development with tests and debug info |
| `release-g++` | GCC | Production optimized build |
| `release-clang++` | Clang | Alternative production build |
| `release-icpc` | Intel Classic | Intel-optimized build |
| `release-icpx` | Intel oneAPI | Latest Intel compiler |

## 🧪 Testing

### Unit Tests

Run the comprehensive unit test suite:

```bash
# Build and run unit tests
cmake --preset debug
cmake --build --preset debug
ctest --preset debug

# Or run tests directly
./build-debug/tests/unit/{{ project_name_underscore }}_unit_tests
```

### Integration Tests

Test downstream package consumption:

```bash
# Run comprehensive downstream tests
./tests/test_downstream.sh
```

This validates that:
- ✅ The library can be consumed via `find_package()`
- ✅ Both static and shared configurations work
- ✅ Debug and release builds are compatible
- ✅ All target properties are correctly exported

## 📦 vcpkg Integration

This library is designed to work seamlessly with vcpkg:

```json
{
  "dependencies": [
    "{{ project_name_vcpkg }}"
  ]
}
```

### Custom vcpkg Registry

For internal Ridge dependencies, the project includes a private registry configuration in `vcpkg-configuration.json`.

## 🚀 Performance Optimizations

Release builds include aggressive optimizations suitable for HFT environments:

- **Architecture Tuning**: `-march=native -mtune=native`
- **Link-Time Optimization**: `-flto` for maximum inlining
- **Fast Math**: `-ffast-math` for numerical computations
- **Aggressive Inlining**: `-finline-functions` for hot paths

## 🛠️ Development

### Example Application

Build the example application to see the library in action:

```bash
cmake --preset debug
cmake --build --preset debug --target {{ project_name_underscore }}_app
./build-debug/{{ project_name_underscore }}_app
```

### Adding New Functions

Since this is a header-only library, add new functions directly to `include/{{ project_name_underscore }}.h`:

```cpp
namespace ridge {
    inline int add_numbers(int a, int b) {
        return a + b;
    }
}
```

All functions must be marked `inline` for header-only libraries.

## 📋 Library Design

### Header-Only Benefits

- **No Link Dependencies**: No separate compilation or linking step
- **Template-Friendly**: Full template code visible at compile time
- **Maximum Inlining**: Compiler can optimize across all function calls
- **Distribution Simplicity**: Single header file deployment

### Best Practices Followed

- ✅ All functions marked `inline`
- ✅ Include guards for header protection
- ✅ Minimal dependencies (STL only)
- ✅ CMake INTERFACE library for proper packaging
- ✅ Comprehensive testing of header-only usage

## 🤝 Contributing

1. **Header-Only Rule**: All implementations must be in headers marked `inline`
2. **Testing**: Add tests for new functionality in `tests/unit/`
3. **Documentation**: Update this README for new features
4. **Performance**: Ensure new code maintains HFT performance standards

---

**{{ project_name }} - A blazing-fast C++{{ cpp_standard }} header-only library built for performance.**