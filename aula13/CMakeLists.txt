cmake_minimum_required(VERSION 3.5)
project(Carro VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( carro
                Carro/carro.cpp 
                Carro/main.cpp 
                Carro/motor.cpp)

# define C++11 standard
set_property(TARGET carro PROPERTY CXX_STANDARD 11)

add_executable( banco
                Banco/cliente.cpp  
                Banco/conta.cpp  
                Banco/main.cpp)

# define C++11 standard
set_property(TARGET banco PROPERTY CXX_STANDARD 11)

# The end