#include "../include/seguranca.hpp"
using namespace std;

seguranca::seguranca()
{

}

void seguranca::setChave(string chave)
{
    this->chave = chave;
}

string seguranca::getChave()
{
    return chave;
}