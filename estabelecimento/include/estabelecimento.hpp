#ifndef ESTABELECIMENTO
#define ESTABELECIMENTO
#include "cliente.hpp"
#include "produto.hpp"
#include "vector_supemercado.hpp"

#include <string>
using namespace std;

class estabelecimento{
    public:
    string caixa;
    vector_supemercado <produto> produtos;
    vector_supemercado <produto> produtosVendidos;
    int numero;
    vector_supemercado <cliente> clientes;
    double saldo;
    static int quantidadeContas;

    estabelecimento(string caixa);
    ~estabelecimento();

    void gravar();
    void gerarCaixa();
    void listar();
    produto venda(int codigo);
    produto venda(string nome);
    void add(produto p);
    void addAllCaixa();
    void escrever(produto produto);
    void reabastecer(produto produto);
    static bool ordenaPorCodigo(produto a, produto b);
    static bool compare(string s1, string s2);
};
#endif
