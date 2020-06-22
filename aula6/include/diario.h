
#ifndef DIARIO_H
#define DIARIO_H
#include <string>
#include "mensagem.h"

struct Diario {
	Mensagem* messagens;

  bool adicionar(Mensagem mensagem);
  void listar();
  void listarPorData(Data data);
};

#endif