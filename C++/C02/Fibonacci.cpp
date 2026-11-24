#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cout << "O valor de N deve estar entre 1 e 99." << endl;
        return 0;
    }

    int termo1 = 0;
    int termo2 = 1;

    cout << termo1 << " " << termo2;

    for (int i = 2; i < N; i++) {
        int proximoTermo = termo1 + termo2;
        cout << " " << proximoTermo;
        termo1 = termo2;
        termo2 = proximoTermo;
    }

    cout << endl;

    return 0;
}
