#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    double notas[N];
    double soma = 0;

    for (int i = 0; i < N; i++) {
        cin >> notas[i];
        soma += notas[i];
    }

    double media = soma / N;
    int acimaMedia = 0;
    int abaixoMedia = 0;

    for (int i = 0; i < N; i++) {
        if (notas[i] >= media) {
            acimaMedia++;
        } else {
            abaixoMedia++;
        }
    }

    cout << "Media da turma: " << fixed << setprecision(2) << media << endl;
    cout << "Alunos com nota acima da media: " << acimaMedia << endl;
    cout << "Alunos com nota abaixo da media: " << abaixoMedia << endl;

    return 0;
}
