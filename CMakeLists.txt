cmake_minimum_required(VERSION 3.20)

project(Radye_Engine CXX)

# C/CXX standards
include(tools/cmake/c_standards.cmake)
include(tools/cmake/cxx_standards.cmake)
c_standard_17()
cxx_standard_17()

# Engine Entrypoint
add_executable(radye_engine)

# External
include(tools/cmake/thirdparty.cmake)
include_glfw(lib-vc2022)

# Sources
add_subdirectory(src)
