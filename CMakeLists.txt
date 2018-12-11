
# CMake requirements
cmake_minimum_required(VERSION 3.0)

# Project Name
project(ceres_avx_test)

# Compiler options
set(CMAKE_CXX_COMPILER clang++)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
add_compile_options(-std=c++17)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-fno-tree-vectorize)
add_compile_options(-march=native)

# Ceres
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIR})

# Exectuable
add_executable(test_ceres src/test_ceres.cpp src/test_cost_function.cpp src/test_cost_function.h src/point2.h)
target_link_libraries(test_ceres glog ceres)
