cmake_minimum_required(VERSION 3.5)
project(Banco VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable(banco
            src/agencia.cpp  
            src/main.cpp  
            src/banco.cpp  
            src/cliente.cpp  
            src/clientePJ.cpp
            src/fila.cpp
            src/gerente.cpp
            src/app.cpp
            src/caixa.cpp
            src/clientePF.cpp
            src/conta.cpp
            src/funcionario.cpp  
            src/seguranca.cpp
            include/agencia.hpp  
            include/banco.hpp  
            include/cliente.hpp  
            include/clientePJ.hpp
            include/fila.hpp
            include/gerente.hpp
            include/app.hpp
            include/caixa.hpp
            include/clientePF.hpp
            include/conta.hpp
            include/funcionario.hpp  
            include/seguranca.hpp)

# define C++11 standard
set_property(TARGET banco PROPERTY CXX_STANDARD 11)

# The end