#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int contatos[1000];

    for (int i = 0; i < N; i++) {
        cin >> contatos[i];
    }

    int menor = contatos[0];
    int maior = contatos[0];

    for (int i = 1; i < N; i++) {
        if (contatos[i] < menor) {
            menor = contatos[i];
        }

        if (contatos[i] > maior) {
            maior = contatos[i];
        }
    }

    cout << "Menor numero de contatos: " << menor << endl;
    cout << "Maior numero de contatos: " << maior << endl;

    return 0;
}
