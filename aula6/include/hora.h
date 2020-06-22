
#ifndef HORA_H
#define HORA_H
#include <string>


struct Hora {
  int hora;
  int minuto;
  int segundo;

	std::string get_current_time();
};

#endif