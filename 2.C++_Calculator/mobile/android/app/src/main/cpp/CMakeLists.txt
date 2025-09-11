# CMakeLists.txt for Android C++ Calculator Integration

cmake_minimum_required(VERSION 3.18.1)

# Set the project name
project("calculator_ffi")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the C++ core files
set(CORE_PATH "../../../../../../../core")

# Add the core C++ source files
set(CORE_SOURCES
    ${CORE_PATH}/CalculatorEngine.cpp
    ${CORE_PATH}/Memory.cpp
    ${CORE_PATH}/TrigCalculator.cpp
)

# Add the FFI bridge source file
set(FFI_SOURCES
    ../../../cpp/calculator_ffi.cpp
)

# Create the shared library
add_library(
    calculator_ffi
    SHARED
    ${CORE_SOURCES}
    ${FFI_SOURCES}
)

# Include directories
target_include_directories(
    calculator_ffi
    PRIVATE
    ${CORE_PATH}
    ../../../cpp
)

# Find the log library
find_library(log-lib log)

# Link libraries
target_link_libraries(
    calculator_ffi
    ${log-lib}
    android
)

# Compiler flags
target_compile_options(
    calculator_ffi
    PRIVATE
    -Wall
    -Wextra
    -O3
    -frtti
    -fexceptions
)

# Define preprocessor macros
target_compile_definitions(
    calculator_ffi
    PRIVATE
    ANDROID
    __ANDROID_API__=21
)