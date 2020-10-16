#include "../include/exceptions.hpp"

#include <iostream>

using namespace std;

exceptions::exceptions(){

}

exceptions::~exceptions(){
    
}
void exceptions::erroArquivo(){
    cerr << "Arquivo não existente ou sem permissão de leitura." << endl;
}

void exceptions::erroInesperado(){
    cout << "Aconteceu um erro inesperado no sistema de " << this->tipoEstabelecimento << " ."<< endl;
}

void exceptions::setTipoEstabelecimento(string tipoEstabelecimento){
    this->tipoEstabelecimento = tipoEstabelecimento;
}