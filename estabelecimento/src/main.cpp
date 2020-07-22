#include "../include/appRestaurante.hpp"
#include "../include/appSupermercado.hpp"

int main(int argc, char *argv[])
{
    string option = "-1";
    appSupermercado supermercado("supermercado/estoque.csv", "supermercado/caixa.csv", "supermercado/fornecedor.csv");
    appRestaurante restaurante("restaurante/menu.csv", "restaurante/caixa.csv");
    while (option != "1" || option != "2")
    {
        cout << "........................" << endl;
        cout << "MENU" << endl;
        cout << "1) SUPERMERCADO" << endl
             << "2) RESTAURANTE" << endl
             << "OPÇÃO:";
        getline(cin, option);
        if (option == "1")
        {
            return supermercado.runSupermercado();
        }
        else if (option == "2")
        {
            return restaurante.runRestaurante();
        }
        else
            cout << "erro (opção invalida)." << endl;
    }
    return 1;
}
