#include "../include/produto.hpp"

produto::produto(string nome, int codigo, string unidadeMedida, double preco,int quantidadeEstoque,int quantidadeVendida) 
    : nome(nome), codigo(codigo), unidadeMedida(unidadeMedida), preco(preco), quantidadeEstoque(quantidadeEstoque), quantidadeVendida(quantidadeVendida){
}

produto::produto(){
    this -> quantidadeEstoque = 0;
    this -> quantidadeVendida = 0;
}

produto::~produto(){
    
}