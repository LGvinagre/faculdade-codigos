#include <iostream>
using namespace std;

struct Gladiador {
    string nome;
    int forca, habilidade, idade, vida;
};

int potencia(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    return base * potencia(base, exp - 1);
}

int ataque(Gladiador gladiador) {
    return gladiador.forca + potencia(2, gladiador.habilidade);
}

bool combate(Gladiador g1, Gladiador g2) {
    while (g1.vida > 0 && g2.vida > 0) {
        g2.vida -= ataque(g1);
        g1.vida -= ataque(g2);
    }
    return (g2.vida <= 0);
}

int main() {
    Gladiador gladiadores[1000];
    int qtd = 0;
    int opcao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Cadastrar gladiador\n";
        cout << "2. Fazer batalha\n";
        cout << "3. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            // Cadastro
            Gladiador g;
            cout << "Digite o nome do gladiador: ";
            cin >> g.nome;
            cout << "Digite a forca: ";
            cin >> g.forca;
            cout << "Digite a habilidade: ";
            cin >> g.habilidade;
            cout << "Digite a idade: ";
            cin >> g.idade;
            g.vida = 100;
            gladiadores[qtd++] = g;
            cout << "Gladiador cadastrado com sucesso!\n";

        } else if (opcao == 2) {
            // Batalha
            if (qtd < 2) {
                cout << "Cadastre pelo menos dois gladiadores antes de batalhar.\n";
                continue;
            }

            cout << "\nLista de gladiadores:\n";
            for (int i = 0; i < qtd; i++) {
                cout << i << " - " << gladiadores[i].nome << "\n";
            }

            int i1, i2;
            cout << "Digite o indice do primeiro gladiador: ";
            cin >> i1;
            cout << "Digite o indice do segundo gladiador: ";
            cin >> i2;

            if (i1 >= qtd || i2 >= qtd || i1 == i2) {
                cout << "Indices invalidos!\n";
                continue;
            }

            if (combate(gladiadores[i1], gladiadores[i2])) {
                cout << gladiadores[i1].nome << " ganhou a batalha contra " << gladiadores[i2].nome << ".\n";
            } else {
                cout << gladiadores[i2].nome << " ganhou a batalha contra " << gladiadores[i1].nome << ".\n";
            }

        } else if (opcao != 3) {
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 3);

    cout << "Saindo do sistema...\n";
    return 0;
}
