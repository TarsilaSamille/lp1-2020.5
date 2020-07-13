#include "../include/Funcionario.hpp"

using namespace std;

void Funcionario::setNome(string nome)
{
    this->nome = nome;
}
string Funcionario::getNome()
{
    return this->nome;
}

void Funcionario::setEmpresa(Empresa empresa)
{
    this->empresa = empresa;
}
Empresa Funcionario::getEmpresa()
{
    return this->empresa;
}
void Funcionario::setDepartamento(string departamento)
{
    this->departamento = departamento;
}
string Funcionario::getDepartamento()
{
    return this->departamento;
}
void Funcionario::setSalario(double salario)
{
    this->salario = salario;
}
double Funcionario::getSalario()
{
    return this->salario;
}

void Funcionario::setDataAdimissao(tm dataAdimissao)
{
    this->dataAdimissao = dataAdimissao;
}
tm Funcionario::getDataAdimissao()
{
    return this->dataAdimissao;
}