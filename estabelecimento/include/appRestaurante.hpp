#ifndef APP_R
#define APP_R

#include "restaurante.hpp"
#include "fornecedor.hpp"
#include <string>

using namespace std;

class appRestaurante{
    public:
    restaurante restauranteE;

    appRestaurante(string cardapio, string caixa);
    ~appRestaurante();

    int runRestaurante();
};
#endif
