cmake_minimum_required(VERSION 3.5)
project(Carro VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( supemercado
                src/main.cpp
                src/app.cpp
                src/cliente.cpp
                src/estabelecimento.cpp
                src/produto.cpp
                include/app.hpp
                include/cliente.hpp
                include/estabelecimento.hpp
                include/produto.hpp)

# define C++11 standard
set_property(TARGET supemercado PROPERTY CXX_STANDARD 11)

# The end