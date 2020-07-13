#include "../include/Empresa.hpp"

using namespace std;

void Empresa::setNome(string nome)
{
    this->nome = nome;
}
string Empresa::getNome()
{
    return this->nome;
}
void Empresa::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}
string Empresa::getCnpj()
{
    return this->cnpj;
}