
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include "data.h"
#include "hora.h"

struct Mensagem {
    Data data;
    Hora hora;
    std::string content;

    void mostrar_mensagem(std::string mensagem);
    int gravar_mensagem(std::string mensagem);
    int listar_mensagens();
};

#endif