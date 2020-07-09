#include "cliente.hpp"

int cliente::quantidadeClientes;

cliente::cliente(){
    this->quantidadeClientes+=1;
}

cliente::~cliente(){

}
