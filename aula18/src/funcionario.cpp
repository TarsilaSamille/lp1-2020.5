#include "../include/funcionario.hpp"
using namespace std;

funcionario::funcionario()
{

}

funcionario::funcionario(string nome, string cargo, double salario)
{
    this->nome = nome;
    this->cargo = cargo;
    this->salario = salario;
}

void funcionario::setNome(string nome)
{
    this->nome = nome;
}

void funcionario::setCargo(string cargo)
{
    this->cargo = cargo;
}

void funcionario::setSalario(double salario)
{
    this->salario = salario;
}

string funcionario::getNome()
{
    return nome;
}
string funcionario::getCargo()
{
    return cargo;
}

double funcionario::getSalario()
{
    return salario;
}