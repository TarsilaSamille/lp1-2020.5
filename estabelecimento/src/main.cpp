#include "../include/app.hpp"

int main(int argc, char *argv[])
{
    string option = "-1";
    app supermercado("estoque.csv", "caixa.csv", "fornecedor.csv");
    //         cout << "........................" << endl;

    //             app suapermercado("supermercado/estoque.csv", "supermercado/caixa.csv", "supermercado/fornecedor.csv");
    //         cout << "........................" << endl;

     app restaurante("restaurante/menu.csv", "restaurante/caixa.csv");
    while (option != "1" || option != "2")
    {
        cout << "........................" << endl;
        cout << "MENU" << endl;
        cout << "1) SUPEMERCADO" << endl
             << "2) RESTAURANTE" << endl
             << "OPÇÃO:";

        getline(cin, option);        
        if (option == "1")
        {
               cout << "..................2....." << endl;
     return supermercado.runSupermercado(argc, argv);
        }
        else if (option == "2")
        {
            return restaurante.runRestaurante(argc, argv);
        }
        else cout << "erro (opção invalida)." << endl;
    }
    return 1;
}
