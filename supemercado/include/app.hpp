#ifndef APP
#define APP

#include "estabelecimento.hpp"
#include "fornecedor.hpp"
#include <string>

using namespace std;

class app{
    public:
    estabelecimento supemercado;
    fornecedor fornecedorS;

    app(string estoque,string caixa, string fornecedor);
    ~app();
    void menu();
    int run(int argc, char* argv[]);
    int show_usage(string prog_name);
};
#endif
