#include "../include/clientePJ.hpp"
#include <iostream>
using namespace std;

clientePJ::clientePJ()
{
    cnpj = "000.000.000-00";
}

clientePJ::clientePJ(string nome, string cnpj): cliente(nome), cnpj(cnpj){

}

void clientePJ::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}

string clientePJ::getCnpj()
{
    return cnpj;
}