#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>
#include <vector>

struct Diary
{
    Diary(std::string filename);

    std::string filename;
    std::vector <Message> messages;

    void add(std::string message);
    void add(Message m);
    std::vector<Message*> search(std::string s);
    void addAll();
    void write();
};
#endif