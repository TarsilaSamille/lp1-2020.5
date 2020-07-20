#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <string>

using namespace std;

class funcionario {
    private:
        string nome;
        string cargo;
        double salario;
    
    public:
        funcionario();
        funcionario(string nome, string cargo, double salario);

        void setNome(string nome);
        void setCargo(string cargo);
        void setSalario(double salario);

        string getNome();
        string getCargo();
        double getSalario();
};

#endif