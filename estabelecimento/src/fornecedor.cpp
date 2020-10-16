#include "../include/fornecedor.hpp"
#include "../include/produto.hpp"
#include "../include/exceptions.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <regex>

using namespace std;

fornecedor::fornecedor(string filename): filename(filename)
{
    addAll();
}

fornecedor::~fornecedor()
{
    escreverEstoque();
}

void fornecedor::escreverEstoque()
{
    fstream arquivo;
    exceptions e;
    arquivo.open(filename);
    try{
    if (!arquivo.is_open())
    {   //num. inteiro qualquer, a ser tratado pelo catch de int e exibir a mensagem de insucesso na abertura do arquivo
        throw(15);
    }
  }
  catch(int){
      e.erroArquivo();
  }
    arquivo << "PRODUTO,QUANTIDADE" << endl;
    for (auto produto : produtos.getElements())
    {
        arquivo << produto.nome << "," << produto.quantidadeEstoque << "\n";
    }
    arquivo.close();
}

produto fornecedor::repassarProdutos(string nome, int quantidade)
{
    produto p;
    for (size_t i = 0; i < produtos.size(); i++){
        if (compare(produtos.at(i).nome, nome))
        {
            if (produtos.at(i).quantidadeEstoque > 0)
            {
                vector<produto> v= produtos.getElements();
                v[i].quantidadeEstoque -= quantidade;
                produtos.setElements(v);
                p.nome = produtos.at(i).nome;
                p.quantidadeEstoque =  quantidade;
                escreverEstoque();
                return p;
            }
            else
            {
                cout << nome << " sem estoque\n";
                return p;
            }
        }
    }
    cout << nome << " nome invalido\n";
    escreverEstoque();
    return p;
}

void fornecedor::listarProdutos()
{
    cout << "ESTOQUE FORNECEDOR" << "\n";
    for (auto i : produtos)
    {
        if (i.quantidadeEstoque > 0)
            cout << i.nome << "-" << i.quantidadeEstoque << "\n";
    }
}

void fornecedor::add(produto p)
{
    produtos.push(p);
}

void fornecedor::addAll()
{
    fstream arquivo;
    arquivo.open(filename);
    if (!arquivo.is_open())
    {
        cerr << "Arquivo não existente ou sem permissão FORNECEDOR";
    }
    produto p;
    string msg, quantidade;
    while (!arquivo.eof())
    {
        getline(arquivo, msg);
        if (msg.size() == 0)
        {
            continue;
        }
        vector<string> strings;
        istringstream f(msg);
        string s;
        if (msg.rfind("PRODUTO", 0) != 0 && msg.rfind(",", 0) != 0)
        {
            while (getline(f, s, ','))
            {
                strings.push_back(s);
            }
            quantidade = strings[1];
            p.nome = strings[0];
            p.quantidadeEstoque = atoi(quantidade.c_str());
            add(p);
        }
    }
    arquivo.close();
}

bool fornecedor::ordenaPorCodigo(produto a, produto b)
{
    return a.codigo < b.codigo;
}

bool fornecedor::compare(string s1, string s2)
{
    string comAcentos = "ÁÂÀÃáâàãÉÊÈéêèÍÎÌíîìÓÔÒÕóôòõÚÛúûùÇç";
    string semAcentos = "AAAAaaaaEEEeeeIIIiiiOOOOooooUUuuuCc";
    s1.erase(std::remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    s2.erase(std::remove_if(s2.begin(), s2.end(), ::isspace), s2.end());
    for (int i = 0; i < (int)comAcentos.length(); i++)
    {
        replace(s1.begin(), s1.end(), comAcentos[i], semAcentos[i]);
        replace(s2.begin(), s2.end(), comAcentos[i], semAcentos[i]);
        break;
    }

    for (int i = 0; i < (int)comAcentos.length(); i++)
    {
        s1.erase(remove(s1.begin(), s1.end(), comAcentos[i]), s1.end());
        s2.erase(remove(s2.begin(), s2.end(), comAcentos[i]), s2.end());
    }
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    return s1 == s2;
}
