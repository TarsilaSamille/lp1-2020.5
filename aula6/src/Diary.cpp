#include "../include/Diary.h"
#include "../include/Message.h"
#include "../include/Time.h"
#include "../include/Date.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Diary::Diary(string filename)
    : filename(filename)
{
  addAll();
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
  messages.push_back(message);
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
  arquivo << "- " << t.get_current_time() << " " << messages[messages.size() - 1].content << "\n";
  arquivo.close();
}

vector<Message *> Diary::search(string s)
{
  vector<Message *> msgs;
  for (size_t i = 0; i < messages.size(); i++)
  {
      size_t found = messages[i].content.find(s);
      if (found != string::npos)
      {
        msgs.push_back(&messages[i]);
      }
  }
    return msgs;
}
