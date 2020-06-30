#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App
{
    Diary diary;

    App(std::string filename);
    int run(int argc, char* argv[]);
    int show_usage(std::string prog_name);
    void add();
    void add(std::string message);
    void search();
    void search(std::string message);
    void list_messages();
    void show_mensage(std::string message);
};
#endif