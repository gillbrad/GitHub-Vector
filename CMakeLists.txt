cmake_minimum_required (VERSION 3.22)

set(CXX g++)

# Prevents cmake from dropping down to al older version of c++ if it
# does not support the requested version of c++
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_COMPILER g++)

enable_language(CXX)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE True)

project(Vector_Proj)

include_directories(include)

add_executable( Vector
                src/main.cpp
                src/fileIO.cpp
                src/data.cpp
                src/unitTest.cpp
              )
