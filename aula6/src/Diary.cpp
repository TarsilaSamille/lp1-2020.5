#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Time.h"
#include "../include/Date.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Diary::Diary(string filename)
    : filename(filename), messages_capacity(10), messages_size(0),
      messages(nullptr)
{
  messages = new Message[messages_capacity];
}

void Diary::add(string messageContent)
{
  Date d;
  Time t;
  if (messages_size < messages_capacity)
  {
    Message m;
    m.content = messageContent;
    m.date.set_from_string(d.get_current_date());
    m.time.set_from_string(t.get_current_time());
    messages[messages_size] = m;
    messages_size++;
  }
  // adicionar mensagem no array de mensagens
}

void Diary::write()
{
  Date d;
  Time t;
  fstream arquivo;
  arquivo.open(filename, fstream::app);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão de leitura.";
  }
  if (!d.data_existe())
  {
    if (arquivo.tellg() != 0)
    {
      arquivo << "\n";
    }
    arquivo << "#" << d.get_current_date() << "\n\n";
  }
  arquivo << "- " << t.get_current_time() << " " << messages[messages_size].content << "\n";
  messages_size++;
  arquivo.close();
}
