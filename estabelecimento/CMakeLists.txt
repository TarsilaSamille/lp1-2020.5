cmake_minimum_required(VERSION 3.5)
project(Estabelecimento VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( estabelecimento
                src/main.cpp
                src/cliente.cpp
                src/estabelecimento.cpp
                src/restaurante.cpp
                src/supermercado.cpp
                src/produto.cpp
                src/fornecedor.cpp
                src/appSupermercado.cpp
                src/appRestaurante.cpp
                src/exceptions.cpp
                include/appSupermercado.hpp
                include/appRestaurante.hpp
                include/cliente.hpp
                include/estabelecimento.hpp
                include/restaurante.hpp
                include/supermercado.hpp
                include/produto.hpp
                include/fornecedor.hpp
                include/vector_supemercado.hpp
                include/exceptions.hpp)

# define C++11 standard
set_property(TARGET estabelecimento PROPERTY CXX_STANDARD 11)

# The end