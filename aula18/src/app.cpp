#include "../include/app.hpp"
#include "../include/banco.hpp"
#include <iostream>
#include <string>
using namespace std;

app::app()
{
    bancoA = banco();
}

void app::add()
{
    string nome;
    string agencia;
    cout << "cliente: ";
    getline(cin, nome);
    cout << endl << "agencia: " << endl;
    getline(cin, agencia);

    add(nome, agencia);
}

void app::add(string nome, string agencia)
{
    bancoA.add(nome, agencia);
}

void app::show_qty()
{
    cout << "Contas cadastradas: " << bancoA.qtd_contas() << endl;
}


void app::print_menu()
{
    cout << "........................" << endl;
    cout <<  "MENU" << endl;
    cout << "1) ADCIONAR CONTA" << endl << "2) QUANTIDADE DE CONTA" <<  endl 
     << endl << endl << "0) END" << endl;
}

int app::run()
{
    int option = -1;
    while(option != 0)
    {
        print_menu();
        cin >> option;
        cin.ignore();
        cout << endl << endl;
        switch(option)
        {
            case 1: add(); break;
            case 2: show_qty(); break;
            case 0: break;
            default: cout << "erro (opção invalida)." << endl; break;
        }
    }
    return option;
}