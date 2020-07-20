#include "../include/cliente.hpp"
#include <iostream>
using namespace std;

cliente::cliente()
{

}

cliente::cliente(string nome)
{
    this->nome = nome;
}

void cliente::setNome(string nome)
{
    this->nome = nome;
}

string cliente::getNome()
{
    return nome;
}