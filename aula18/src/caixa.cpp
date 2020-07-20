#include "../include/caixa.hpp"
using namespace std;

caixa::caixa()
{

}

void caixa::setQuebraCaixa(double quebra_caixa)
{
    this->quebra_caixa = quebra_caixa;
}

double caixa::getQuebraCaixa()
{
    return quebra_caixa;
}