#include "../include/gerente.hpp"
using namespace std;

gerente::gerente()
{

}

void gerente::setChaveAcesso(string chave_acesso)
{
    this->chave_acesso = chave_acesso;
}

string gerente::getChaveAcesso()
{
    return chave_acesso;
}