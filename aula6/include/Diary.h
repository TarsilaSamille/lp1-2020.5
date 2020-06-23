#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(std::string filename);

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(std::string message);
    void write();
};
#endif