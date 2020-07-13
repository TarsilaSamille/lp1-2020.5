cmake_minimum_required(VERSION 3.5)
project(Empresa VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( empresa
                src/main.cpp
                src/Empresa.cpp
                src/Funcionario.cpp
                include/Empresa.hpp
                include/Funcionario.hpp)

# define C++11 standard
set_property(TARGET empresa PROPERTY CXX_STANDARD 11)

# The end