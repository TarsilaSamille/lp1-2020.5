#include "../include/appRestaurante.hpp"
#include "../include/appSupermercado.hpp"
#include "../include/exceptions.hpp"

int main(int argc, char *argv[])
{
    string option = "-1";
    exceptions e;
    appSupermercado supermercado("supermercado/estoque.csv", "supermercado/caixa.csv", "supermercado/fornecedor.csv");
    appRestaurante restaurante("restaurante/menu.csv", "restaurante/caixa.csv");
    try{
        //descomentar para testar o catch de erro genérico.
        //throw (25);
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
    }
    catch (bad_alloc E){   
        cout << "Problemas com alocação de memória\n" << endl;     
       
    }
    catch(...){
        e.erroInesperado();
    }

    return 1;
}
