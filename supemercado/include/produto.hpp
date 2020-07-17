#ifndef PRODUTO
#define PRODUTO
#include <string>

using namespace std;

class produto{
    public:
    string nome;
    int codigo;
    string unidadeMedida;
    double preco;
    int quantidadeEstoque;
    int quantidadeVendida;

    produto(string nome, int codigo, string unidadeMedida, double preco,int quantidadeEstoque, int quantidadeVendida);
    produto(string nome, int quantidadeEstoque);
    produto();
    ~produto();
};

#endif
