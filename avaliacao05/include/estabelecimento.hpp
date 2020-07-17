#ifndef ESTABELECIMENTO
#define ESTABELECIMENTO
#include "cliente.hpp"
#include "produto.hpp"
#include "vector_supemercado.hpp"

#include <string>
using namespace std;

class estabelecimento{
    public:
    string estoque;
    string caixa;
    vector_supemercado <produto> produtos;
    vector_supemercado <produto> produtosVendidos;
    vector_supemercado <cliente> clientes;
    int numero;
    double saldo;
    static int quantidadeContas;

    estabelecimento(string estoque,string caixa);
    ~estabelecimento();

    produto venda(int codigo);
    produto venda(string nome);
    void gerarCaixa();
    void listar();
    void add(produto p);
    void addAll();
    void addAllCaixa();
    void escrever(produto produto);
    void escreverEstoque();
    void reabastecer(produto produto);
    static bool ordenaPorCodigo(produto a, produto b);
    static bool compare(string s1, string s2);
};
#endif
