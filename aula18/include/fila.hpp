#ifndef FILA
#define FILA

using namespace std;

template<class T>
class fila {
    private:
    T* clientes;
    int tamanho;
    int primeiro;
    int ultimo;
    int cont;

    public:
    fila(int tamanho);

    void adiciona(T item);
    T* remove();
    T* proximo();
    int contagem();
    bool isEmpty();
    bool isFull();
    void imprime();

};
#endif
