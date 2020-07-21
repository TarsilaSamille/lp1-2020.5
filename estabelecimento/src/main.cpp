#include "../include/app.hpp"

int main(int argc, char *argv[])
{
    string option = "-1";
    app supermercado("supermercado/estoque.csv", "supermercado/caixa.csv", "supermercado/fornecedor.csv");
//    app restaurante("restaurante/menu.csv", "restaurante/caixa.csv");
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
               cout << "..................2....." << endl;
     return supermercado.runSupermercado();
        }
        // else if (option == "2")
        // {
        //     return restaurante.runRestaurante();
        // }
        // else cout << "erro (opção invalida)." << endl;
    }
    return 1;
}
