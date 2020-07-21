#ifndef SUPERMERCADO
#define SUPERMERCADO

#include <string>
#include "estabelecimento.hpp"
#include "fornecedor.hpp"

using namespace std;

class supermercado : public estabelecimento {
    public:
        string estoque;
        fornecedor fornecedorS;

        supermercado(string estoque, string caixa, string fornecedorF);
        supermercado(string caixa, string fornecedorF) ;
        ~supermercado();

        void escreverEstoque();
        void addAll();
    void gravar();

};
#endif