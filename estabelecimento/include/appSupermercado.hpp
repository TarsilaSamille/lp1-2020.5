#ifndef APP_S
#define APP_S

#include "supermercado.hpp"
#include "fornecedor.hpp"
#include <string>

using namespace std;

class appSupermercado{
    public:
    supermercado supermercadoE;

    appSupermercado(string estoque,string caixa, string fornecedor);
    ~appSupermercado();

    int runSupermercado();
};
#endif
