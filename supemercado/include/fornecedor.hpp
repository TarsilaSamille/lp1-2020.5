#ifndef FORNECEDOR
#define FORNECEDOR
#include "produto.hpp"
#include "estabelecimento.hpp"
#include "vector_supemercado.hpp"

#include <string>
using namespace std;

class fornecedor{
    public:
    string filename;
    vector_supemercado <produto> produtos;

    fornecedor(string filename);
    fornecedor();
    ~fornecedor();

    void add(produto p);
    void addAll();
    void escreverEstoque();
    void escrever();
    void listarProdutos();
    produto repassarProdutos(string codigo, int quiantidade);
    static bool ordenaPorCodigo(produto a, produto b);
    static bool compare(string s1, string s2);
};
#endif
