#include "../include/clientePF.hpp"
#include <iostream>
using namespace std;

clientePF::clientePF()
{
    cpf = "000.000.000-00";
}

clientePF::clientePF(string nome, string cpf): cliente(nome), cpf(cpf){

}


void clientePF::setCpf(string cpf)
{
    this->cpf = cpf;
}

string clientePF::getCpf()
{
    return cpf;
}