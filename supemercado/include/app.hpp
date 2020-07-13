#ifndef APP
#define APP

#include "estabelecimento.hpp"
#include <string>

using namespace std;

class app{
    public:
    estabelecimento supemercado;

    app(string estoque,string caixa );
    ~app();
    void menu();
    int run(int argc, char* argv[]);
    int show_usage(string prog_name);
};
#endif
