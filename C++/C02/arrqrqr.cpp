#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    string nome;
    int quantidade;
    string categoria;
};

const string NOME_ARQUIVO = "estoque.txt";
const int MAX_ITENS = 100;
Item estoque[MAX_ITENS];
int totalItens = 0;

void adicionarItem() {
    if (totalItens < MAX_ITENS) {
        cout << "Nome do item: ";
        cin.ignore();
        getline(cin, estoque[totalItens].nome);
        cout << "Quantidade: ";
        cin >> estoque[totalItens].quantidade;
        cout << "Categoria: ";
        cin.ignore();
        getline(cin, estoque[totalItens].categoria);

        ofstream arquivo(NOME_ARQUIVO, ios::app); // Abre o arquivo para escrita, em modo de acrescentar ao final
        if (arquivo.is_open()) {
            arquivo << estoque[totalItens].nome << "," << estoque[totalItens].quantidade << "," << estoque[totalItens].categoria << endl;
            arquivo.close();
            totalItens++;
            cout << "Item adicionado ao estoque.\n";
        } else {
            cout << "Erro ao abrir o arquivo.\n";
        }
    } else {
        cout << "O estoque está cheio. Não é possível adicionar mais itens.\n";
    }
}

void mostrarItens() {
    ifstream arquivo(NOME_ARQUIVO);
    if (arquivo.is_open()) {
        string linha;
        cout << "\nItens cadastrados:\n";
        while (getline(arquivo, linha)) {
            cout << linha << endl;
        }
        arquivo.close();
    } else {
        cout << "Nenhum item cadastrado.\n";
    }
}

int main() {
    int opcao;

    while (true) {
        cout << "\n1. Adicionar novo item\n";
        cout << "2. Mostrar itens cadastrados\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                mostrarItens();
                break;
            case 3:
                cout << "Saindo...\n";
                return 0;
            default:
                cout << "Opção inválida!\n";
        }
    }

    return 0;
}
