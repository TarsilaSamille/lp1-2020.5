#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

#include "../include/app.hpp"
#include "../include/fornecedor.hpp"
#include "../include/cliente.hpp"

using namespace std;

app::app(string estoque, string caixa, string fornecedorFilename)
    : supermercadoE(estoque, caixa, fornecedorFilename), restauranteE(caixa)
{
}

app::app(string cardapio, string caixa)
    : restauranteE(cardapio, caixa), supermercadoE(caixa, "restaurante/vazio.csv")
{
}

app::~app()
{
}

int app::runSupermercado()
{
        string nome, saldo, cod, quantidade;
        cout << "cliente\nnome:";
        getline(cin, nome);
        cout << "saldo:";
        getline(cin, saldo);
        cliente c(nome, atol(saldo.c_str()));
        string opt = "1";
        while (opt != "0")
        {
            cout << "Supermercado 1.0\n";
            cout << "Selecione uma ação:\n";
            cout << "1) Listar produtos supemercado\n";
            cout << "2) Adicionar produto a sacola\n";
            cout << "3) Listar produtos sacola\n";
            cout << "4) Listar produtos fornecedor\n";
            cout << "5) Reabasticer o estoque do estabelecimento\n";
            cout << "6) Adicionar saldo\n";
            cout << "7) Ver saldo\n";
            cout << "0) Finalizar\n";
            cout << "opção:";
            getline(cin, opt);
            if (opt == "2")
            {
                cout << "nome dos produtos:";
                getline(cin, cod);
                cod.erase(std::remove_if(cod.begin(), cod.end(), ::isspace), cod.end());
                istringstream f(cod);
                vector<string> nomes = {};
                string s;
                while (getline(f, s, ','))
                {
                    nomes.push_back(s);
                }

                for (auto nome : nomes)
                {
                    produto ptr = supermercadoE.venda(nome);
                    if (ptr.nome != "")
                        c.compra(ptr);
                }
            }
            else if (opt == "1")
            {
                supermercadoE.listar();
            }
            else if (opt == "3")
            {
                c.verSacola();
            }
            else if (opt == "4")
            {
                supermercadoE.fornecedorS.listarProdutos();
            }
            else if (opt == "5")
            {
                cout << "produto\nnome:";
                getline(cin, nome);
                cout << "quantidade:";
                getline(cin, quantidade);
                cod.erase(std::remove_if(cod.begin(), cod.end(), ::isspace), cod.end());
                supermercadoE.reabastecer(supermercadoE.fornecedorS.repassarProdutos(nome, atoi(quantidade.c_str())));
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
                cout << "invalido\n";
            }
        }
        cout << "inicializar novo cliente? (s/N):\n";
        getline(cin, opt);
        if (opt == "S" || opt == "s")
            runSupermercado();
    return 1;
}
int app::runRestaurante()
 {
//     if (argc == 1)
//     {
//         string nome, saldo, cod, quantidade;
//         cout << "cliente\nnome:";
//         getline(cin, nome);
//         cout << "saldo:";
//         getline(cin, saldo);
//         cliente c(nome, atol(saldo.c_str()));
//         string opt = "1";
//         while (opt != "0")
//         {
//             cout << "Supermercado 1.0\n";
//             cout << "Selecione uma ação:\n";
//             cout << "1) Listar produtos supemercado\n";
//             cout << "2) Adicionar produto a sacola\n";
//             cout << "3) Listar produtos sacola\n";
//             cout << "4) Listar produtos fornecedor\n";
//             cout << "5) Reabasticer o estoque do estabelecimento\n";
//             cout << "6) Adicionar saldo\n";
//             cout << "7) Ver saldo\n";
//             cout << "0) Finalizar\n";
//             cout << "opção:";
//             getline(cin, opt);
//             if (opt == "2")
//             {
//                 cout << "nome dos produtos:";
//                 getline(cin, cod);
//                 cod.erase(std::remove_if(cod.begin(), cod.end(), ::isspace), cod.end());
//                 istringstream f(cod);
//                 vector<string> nomes = {};
//                 string s;
//                 while (getline(f, s, ','))
//                 {
//                     nomes.push_back(s);
//                 }

//                 for (auto nome : nomes)
//                 {
//                     produto ptr = supermercadoE.venda(nome);
//                     if (ptr.nome != "")
//                         c.compra(ptr);
//                 }
//             }
//             else if (opt == "1")
//             {
//                 supermercadoE.listar();
//             }
//             else if (opt == "3")
//             {
//                 c.verSacola();
//             }
//             else if (opt == "4")
//             {
//                 supermercadoE.fornecedorS.listarProdutos();
//             }
//             else if (opt == "5")
//             {
//                 cout << "produto\nnome:";
//                 getline(cin, nome);
//                 cout << "quantidade:";
//                 getline(cin, quantidade);
//                 cod.erase(std::remove_if(cod.begin(), cod.end(), ::isspace), cod.end());
//                 supermercadoE.reabastecer(supermercadoE.fornecedorS.repassarProdutos(nome, atoi(quantidade.c_str())));
//             }
//             else if (opt == "6")
//             {
//                 cout << "saldo:";
//                 getline(cin, saldo);
//                 c.saldo = atoi(saldo.c_str());
//             }
//             else if (opt == "7")
//             {
//                 cout << "saldo:R$" << c.saldo << endl;
//             }
//             else if (opt == "0")
//             {
//                 c.registro();
//                 break;
//             }
//             else
//             {
//                 cout << "invalido\n";
//             }
//         }
//         cout << "inicializar novo cliente? (s/N):\n";
//         getline(cin, opt);
//         if (opt == "S" || opt == "s")
//                         runREstaurante(argc, argv);
//     }
    return 1;
}
