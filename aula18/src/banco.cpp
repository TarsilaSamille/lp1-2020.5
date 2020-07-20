#include "../include/banco.hpp"
#include <vector>
#include <iostream>
using namespace std;

banco::banco()
{

}

void banco::add(string nome, string agencia)
{
    conta conta(nome, agencia);
    contas.push_back(conta);
}

int banco::qtd_contas()
{
    return contas.size();
}