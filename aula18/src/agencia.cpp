#include "../include/agencia.hpp"
#include <iostream>
using namespace std;

agencia::agencia(string nome)
{
    this->nome = nome;
    id = "xxx-x";
}

agencia::agencia()
{
}

void agencia::setNome(string nome)
{
    this->nome = nome;
}

string agencia::getNome()
{
    return nome;
}

void agencia::setId(string id)
{
    this->id = id;
}

string agencia::getId()
{
    return id;
}