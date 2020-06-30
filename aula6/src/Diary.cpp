#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Time.h"
#include "../include/Date.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Diary::Diary(string filename)
    : filename(filename), messages_capacity(2), messages_size(0),
      messages(nullptr)
{
  messages = new Message[messages_capacity];
  addAll();
}

Diary::~Diary()
{
  delete[] messages;
}

void Diary::add(string messageContent)
{
  Date d;
  Time t;
  Message m;
  m.content = messageContent;
  m.date.set_from_string(d.get_current_date());
  m.time.set_from_string(t.get_current_time());
  add(m);
}

void Diary::add(Message message)
{
  if (messages_size < messages_capacity)
  {
    messages[messages_size] = message;
    messages_size++;
  }
  else
  {
    messages_capacity *= 2;
    Message *new_array = new Message[messages_capacity];
    for (size_t i = 0; i < messages_size; i++)
    {
      new_array[i] = messages[i];
    }
    delete[] messages;
    messages = new_array;
    messages[messages_size] = message;
    messages_size++;
  }
}

void Diary::addAll()
{
  Date d;
  Time t;
  ifstream arquivo;
  arquivo.open(filename);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão";
  }
  string msg;
  Message m;
  while (!arquivo.eof())
  {
    getline(arquivo, msg);
    if (msg.size() == 0)
    {
      continue;
    }
    if (msg.rfind("#", 0) == 0)
    {
      d.set_from_string(msg.substr(1, 10));
      m.date = d;
      continue;
    }
    m.content = msg.substr(10, msg.size());
    ;
    t.set_from_string(msg.substr(2, 10));
    m.time = t;
    add(m);
  }
  arquivo.close();
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
  arquivo << "- " << t.get_current_time() << " " << messages[messages_size - 1].content << "\n";
  messages_size++;
  arquivo.close();
}

Message *Diary::search(string s)
{
  for (size_t i = 0; i < messages_size; i++)
  {
    size_t found = messages[i].content.find(s);
    if (found != string::npos)
    {
      return &messages[i];
    }
  }

  return nullptr;
}