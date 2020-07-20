#include <iostream>
#include "../include/conta.hpp"
#include "../include/agencia.hpp"
#include "../include/cliente.hpp"
using namespace std;

conta::conta()
{
    
}

conta::conta(string& nome, string& nome_agencia)
{
    clienteA = cliente(nome);
    agenciaA = agencia(nome_agencia);
    saldo = 0;

}

void conta::saque(float quantia)
{
    saldo -= quantia;
}

void conta::deposito(float quantia)
{
    saldo += quantia;
}

void conta::transferencia(float quantia, conta& conta)
{
    saldo -= quantia;
    conta.saldo += quantia;
}