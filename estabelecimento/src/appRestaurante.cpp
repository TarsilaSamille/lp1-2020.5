#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

#include "../include/appRestaurante.hpp"
#include "../include/cliente.hpp"
#include "../include/exceptions.hpp"

using namespace std;

appRestaurante::appRestaurante(string cardapio, string caixa)
    : restauranteE(cardapio, caixa)
{
}

appRestaurante::~appRestaurante()
{
}

int appRestaurante::runRestaurante()
{
    string nome, saldo, cod, quantidade;
    int qtd;
    cout << "cliente\nnome:";
    getline(cin, nome);
    cout << "saldo:";
    getline(cin, saldo);
    cliente c(nome, atol(saldo.c_str()));
    string opt = "1";
    exceptions e;
    try{
        //descomentar para testar o catch de erro genérico
        //throw (15);
        while (opt != "0")
        {
            cout << "Restaurante 1.0\n";
            cout << "Selecione uma ação:\n";
            cout << "1) Listar menu\n";
            cout << "2) Fazer pedidos\n";
            cout << "3) Listar pedidos\n";
            cout << "6) Adicionar saldo\n";
            cout << "7) Ver saldo\n";
            cout << "0) Finalizar\n";
            cout << "opção:";
            getline(cin, opt);
            if (opt == "2")
            {
                cout << "nome do pedido:";
                getline(cin, nome);
                cout << "quantidade:";
                getline(cin, quantidade);
                produto ptr = restauranteE.venda(nome);
                qtd = atoi(quantidade.c_str());

                for (int i = 0; i < qtd; i++)
                {
                    if (ptr.nome != "")
                        c.compra(ptr);
                }
            }
            else if (opt == "1")
            {
                restauranteE.listar();
            }
            else if (opt == "3")
            {
                c.verSacola();
            }
            else if (opt == "6")
            {
                cout << "saldo:";
                getline(cin, saldo);
                c.saldo = atoi(saldo.c_str());
            }
            else if (opt == "7")
            {
                cout << "saldo:R$" << c.saldo << endl;
            }
            else if (opt == "0")
            {
                c.registro();
                break;
            }
            else
            {
                cout << "opção invalida\n";
            }
        }
    } 
    catch (bad_alloc E){   
        cout << "Problemas com alocação de memória\n" << endl;
    } 
    catch(...){
        e.erroInesperado();
    } 
    cout << "inicializar novo cliente? (s/N):\n";
    getline(cin, opt);
    if (opt == "S" || opt == "s")
        runRestaurante();
    return 1;
}
