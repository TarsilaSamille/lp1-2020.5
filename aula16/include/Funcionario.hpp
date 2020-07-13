#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <string>
#include <ctime>
#include "Empresa.hpp"

using namespace std;

class Funcionario
{
private:
    string nome;
    Empresa empresa;
    double salario;
    string departamento;
    tm dataAdimissao;

public:
    void setNome(string nome);
    string getNome();

    void setEmpresa(Empresa empresa);
    Empresa getEmpresa();

    void setDepartamento(string departamento);
    string getDepartamento();

    void setSalario(double salario);
    double getSalario();

    void setDataAdimissao(tm DataAdimissao);
    tm getDataAdimissao();
    
};
#endif
