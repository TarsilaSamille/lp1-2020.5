#include "../include/fila.hpp"
#include <iostream>
#include <string>
#include "../include/cliente.hpp"
#include "../include/clientePJ.hpp"
#include "../include/clientePF.hpp"
using namespace std;

template<class T>
fila<T>::fila(int tamanho)
{
    this->tamanho=tamanho;
    clientes = new T[tamanho];
    primeiro = -1;
    ultimo = 0;
    cont = 0;
}

template<class T>
bool fila<T>::isEmpty()
{
    if(primeiro == -1) return true;
    else return false;
}

template<class T>
bool fila<T>::isFull()
{
    if(primeiro == ultimo) return true;
    else return false;
}


template<class T>
void fila<T>::adiciona(T item)
{
    if(isFull())
    {
        cout << "fila cheia. Operacao nao realizada." << endl;
    }
    else
    {
        if(isEmpty())
        {
            primeiro = 0;
        }
        clientes[ultimo] = item;
        ultimo = (ultimo+1)%tamanho;
        cont++;
    }   
}

template<class T>
T* fila<T>::remove()
{
    if(isEmpty())
	{
		cout << "fila vazia. Operacao nao realizada" << endl;
		return nullptr;
	}
	else
	{
	    T* rem = &clientes[primeiro];
	    primeiro = (primeiro+1)%tamanho;
		
	    if (primeiro == ultimo)
	    {
	    	primeiro = -1;
	    	ultimo = 0;
    	}
        cont--;
	    return rem;
	}
}

template<class T>
T* fila<T>::proximo()
{
    if(!isEmpty())return &clientes[primeiro];
    else return nullptr;
}

template<class T>
int fila<T>::contagem()
{
    return cont;
}

template<class T>
void fila<T>::imprime()
{
    if(isEmpty())
    {
        cout << "fila vazia." << endl;
    }
    else
    {
        for(int i=0; i<cont; i++)
        {
           cout << "posi " << (primeiro+i)%tamanho << ": " << endl;
           cout << clientes[(i+primeiro)%tamanho] << endl;
        }
    }
        
}


template class fila<int>;
template class fila<float>;
template class fila <double>;
template class fila<string>;
// template class fila<cliente>;
// template class fila<clientePJ>;
// template class fila<clientePF>;
