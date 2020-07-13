#ifndef ESTABELECIMENTO
#define ESTABELECIMENTO
#include "cliente.hpp"
#include "produto.hpp"

#include <string>
#include <vector>
using namespace std;

class estabelecimento{
    public:
    string estoque;
    string caixa;
    vector <produto> produtos;
    vector <produto> produtosVendidos;
    int numero;
    vector <cliente> clientes;
    double saldo;
    static int quantidadeContas;

    estabelecimento(string estoque,string caixa);
    ~estabelecimento();

    void gerarCaixa();
    void listar();
    produto* venda(int codigo);
    produto* venda(string nome);
    void add(produto p);
    void addAll();
    void addAllCaixa();
    void escrever(produto produto);
    void escreverEstoque();
    static bool ordenaPorCodigo(produto a, produto b);
    static bool compare(string s1, string s2);
};
#endif
