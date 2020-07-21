#ifndef APP
#define APP

#include "restaurante.hpp"
#include "supermercado.hpp"
#include "fornecedor.hpp"
#include <string>

using namespace std;

class app{
    public:
    supermercado supermercadoE;
    restaurante restauranteE;

    app(string estoque,string caixa, string fornecedor);
    app(string cardapio, string caixa);
    ~app();

    int runSupermercado();
    int runRestaurante();
};
#endif
