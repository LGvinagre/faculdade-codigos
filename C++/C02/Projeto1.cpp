#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>

using namespace std;

struct Item
{
    int id;
    string nome;
    float preco;
};

void gravarNoArquivo(const string &arquivo, const Item &item)
{
    ofstream gravar(arquivo.c_str(), ios::app);

    if (gravar.is_open())
    {
        gravar << "ID:" << item.id
               << " Nome: " << item.nome
               << " Preco: " << item.preco << endl;

        gravar.close();
    }
    else
    {
        cerr << "Erro ao abrir o arquivo para gravacao." << endl;
    }
}

void removerDoArquivo(const string &arquivo, int idRemover)
{
    ifstream ler(arquivo.c_str());
    ofstream temp("temp.txt");

    if (ler.is_open() && temp.is_open())
    {
        string linha;
        while (getline(ler, linha))
        {
            size_t pos = linha.find(';');
            if (pos!= string::npos)
            {
                string idStr = linha.substr(0, pos);
                int id;
                sscanf(idStr.c_str(), "ID:%d", &id);

                if (id!= idRemover)
                {
                    temp << linha << endl;
                }
            }
        }

        ler.close();
        temp.close();

        remove(arquivo.c_str());
        rename("temp.txt", arquivo.c_str());
    }
    else
    {
        cerr << "Erro ao abrir o arquivo para leitura ou escrita." << endl;
    }
}

int main()
{
    // Configurar a localidade para permitir caracteres especiais
    setlocale(LC_ALL, "");

    int escolhamenu = -1;
    string arquivo = "itens.txt";

    while (escolhamenu!= 0)
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
                {
                    Item novoItem;
                    cout << "Cadastrar novo item selecionado." << endl;
                    cout << "Informe o ID: ";
                    cin >> novoItem.id;
                    cout << "Informe o nome: ";
                    cin.ignore();
                    getline(cin, novoItem.nome);
                    cout << "Informe o preco: ";
                    cin >> novoItem.preco;

                    gravarNoArquivo(arquivo, novoItem);
                    break;
                }
                case 2:
                    cout << "Remover item selecionado." << endl;
                    int idRemover;
                    cout << "Informe o ID do item que deseja remover: ";
                    cin >> idRemover;

                    removerDoArquivo(arquivo, idRemover);
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

        if (escolhamenu!= 0)
        {
            cout << "Pressione Enter para continuar..." << endl;
            cin.ignore();
            cin.get(); 
        }
    }

    return 0;
}