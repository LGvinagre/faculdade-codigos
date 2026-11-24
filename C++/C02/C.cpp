#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int valor;
} Numero;

int main() {
    char frase[100];
    Numero numeros[100]; // Vetor para armazenar os números encontrados
    int quantidade = 0;         // Contador para o número de elementos no vetor

    printf("Digite uma frase: ");
    fgets(frase, 100, stdin); // Lê a frase com espaços

    int i = 0;
    while (frase[i] != '\0') {
        if (isdigit(frase[i])) { // Verifica se o caractere é um dígito
            int numero = 0;

            // Captura o número inteiro (caso tenha mais de um dígito)
            while (isdigit(frase[i])) {
                numero = numero * 10 + (frase[i] - '0');
                i++;
            }

            // Armazena o número na estrutura
            numeros[quantidade].valor = numero;
            quantidade++;
        } else {
            i++;
        }
    }

    // Exibe os números encontrados
    printf("Numeros encontrados:\n");
    for (int j = 0; j < quantidade; j++) {
        printf("%d ", numeros[j].valor);
    }
    printf("\n");

    return 0;
}
