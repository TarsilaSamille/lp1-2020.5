#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>
#include <string>
using namespace std;

class exceptions{
    private:
    string tipoEstabelecimento;

    public:
    exceptions();
    ~exceptions();
    void setTipoEstabelecimento(string tipoEstabelecimento);
    void erroInesperado();
    void erroArquivo();
};

#endif