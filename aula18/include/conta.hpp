#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "agencia.hpp"
#include "cliente.hpp"

using namespace std;

class conta {
    public:
        cliente clienteA;
        agencia agenciaA;
        float saldo;

        conta();
        conta(string& nome, string& nome_agencia);

        void saque(float quantia);
        void deposito(float quantia);
        void transferencia(float quantia, conta& conta);
};
#endif