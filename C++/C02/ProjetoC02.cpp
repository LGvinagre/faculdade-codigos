#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;

int main()
{
    // Configurar a localidade para permitir caracteres especiais
    setlocale(LC_ALL, "");

    int escolhamenu = -1;

    while (escolhamenu != 0)
    {
        // Limpar a tela
        #ifdef _WIN32
            system("cls"); // Limpar a tela no Windows
        #else
            system("clear"); // Limpar a tela no Linux/macOS
        #endif

        cout << "----------MENU----------" << endl;
        cout << "| 1) Cadastrar novo item |" << endl;
        cout << "| 2) Remover item        |" << endl;
        cout << "| 3) Itens no estoque    |" << endl;
        cout << "| 0) Sair                |" << endl; 

        cin >> escolhamenu;

        if (escolhamenu < 0 || escolhamenu > 3)
        {
            cout << "Opção inválida" << endl;
        }
        else
        {
            switch (escolhamenu)
            {
                case 1:
                    cout << "Cadastrar novo item selecionado." << endl;
                    // Adicione aqui o código para cadastrar um novo item
                    break;
                case 2:
                    cout << "Remover item selecionado." << endl;
                    // Adicione aqui o código para remover um item
                    break;
                case 3:
                    cout << "Itens no estoque selecionado." << endl;
                    // Adicione aqui o código para mostrar itens no estoque
                    break;
                case 0:
                    cout << "Saindo..." << endl;
                    // Adicione aqui o código para finalizar o programa, se necessário
                    break;
                default:
                    cout << "Opção inválida" << endl;
            }
        }

        if (escolhamenu != 0)
        {
            cout << "Pressione Enter para continuar..." << endl;
            cin.ignore();
            cin.get(); 
        }
    }

    return 0;
}