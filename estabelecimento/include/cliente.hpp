#ifndef CLIENTE
#define CLIENTE
#include "produto.hpp"
#include "vector_supemercado.hpp"

#include <string>

using namespace std;

class cliente{
    public:
    int codigo;
    string nome;
    double saldo;
    vector_supemercado <produto> sacola;
    static int quantidadeClientes;

    cliente(string nome, double saldo);
    cliente();
    ~cliente();

    void compra(produto &p);
    void verSacola();
    void registro();
    void escrever(string filename);
};
#endif
