#include <iostream>
#include <string>

#include "../include/App.h"

using namespace std;

App::App(string filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add()
{
    string message;
    cout << "Enter your message:";
    getline(cin, message);

    add(message);
}

void App::add(const string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        cout << "-" << message.content;
    }
}

int App::show_usage(string prog_name)
{
  cout << "Uso: " << prog_name << " list" << "\n";
  cout << "Uso: " << prog_name << " add <mensagem>" << "\n";
  return 1;
}
void show_mensage(string message) {
  cout << "Mensagem adicionada:" << message << "\n";
}
