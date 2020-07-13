#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "../include/Empresa.hpp"
#include "../include/Funcionario.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Empresa empresa = Empresa();
    vector<Funcionario> funcionarios;
    vector<string> departamentos = {};
    int j = 0;

    string quantidade, nome, numero, dep;

    cout << "Empresa\nnome:";
    getline(cin, nome);
    cout << "CNPJ:";
    getline(cin, numero);
    cout << "quantidade de funcionários:";
    getline(cin, quantidade);

    cout << "nome dos departamentos(separados por virgula)\n:";
    getline(cin, dep);
    dep.erase(std::remove_if(dep.begin(), dep.end(), ::isspace), dep.end());
    istringstream f(dep);
    string s;
    while (getline(f, s, ','))
    {
        departamentos.push_back(s);
    }

    empresa.setNome(nome);
    empresa.setCnpj(numero);

    time_t t = time(0);
    tm *now = localtime(&t);

    for (int i = 0; i < stoi(quantidade); i++)
    {
        Funcionario f = Funcionario();
        cout << "FUNCIONARIO " << i + 1 << ")\nnome:";
        getline(cin, nome);
        cout << "salario:";
        getline(cin, numero);

        f.setNome(nome);
        f.setEmpresa(empresa);
        f.setSalario(stol(numero));
        f.setDataAdimissao(*now);
        j=0;
        cout << "departamento(digita o numero correspondente)\n";
        for (auto d : departamentos)
        {
            cout << j << ")" << d << endl;
            j++;
        }
        cout << ":";
        getline(cin, numero);

        f.setDepartamento(departamentos[stoi(numero)]);
        funcionarios.push_back(f);
    }
    cout << "\nFUNCIONARIOS:" << endl;
    for (Funcionario f : funcionarios)
    {
        cout << "- Nome: " + f.getNome() + "\n- Departamento: " + f.getDepartamento() + "\n- Salario: R$" << f.getSalario() << endl;
    }
    j = 0;
    cout << j << ")\ndepartamento pra dar o aumento(digita o numero correspondente)";
    for (auto d : departamentos)
    {
        cout << j << ")" << d << endl;
        j++;
    }
    cout << ":";
    getline(cin, numero);

    cout << "\nFUNCIONARIOS:" << endl;
    for (Funcionario f : funcionarios)
    {
        if (f.getDepartamento() == departamentos[stoi(numero)])
        {
            f.setSalario(f.getSalario() * 1.1);
        }
        cout << "- Nome: " + f.getNome() + "\n- Departamento: " + f.getDepartamento() + "\n- Salario: R$" << f.getSalario() << endl;
    }
}
