#ifndef VETOR_SUPEMERCADO
#define VETOR_SUPEMERCADO
#include <iostream>
#include <vector>

using namespace std;

template <class T>

class vector_supemercado{
    private:
    vector<T> elements;

    public:
    using iterator= typename std::vector<T>::iterator;

    vector_supemercado(){
    }
    ~vector_supemercado(){
    }
    iterator begin(){
        return elements.begin();
    }

    iterator end(){
        return elements.end();
    }

    vector<T> erase(iterator v){
        return elements.erase(v);
    }
    size_t size(){
        return elements.size();
    }

    T at(int i){
        return elements[i];
    }

    void push(T e){
        return elements.push_back(e);
    }
    vector<T> getElements() {return elements;}
    void setElements(vector<T> v) {this->elements = v;}
};

#endif