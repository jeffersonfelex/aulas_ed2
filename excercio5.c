/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Programa que utiliza recursão para imprimir o resultado harmonico.
*/

#include <stdio.h>

double calculoDivisao(int n) {
    if (n == 1) {
        return 1.0;
    }
    return 1.0 / n + calculoDivisao(n - 1);
}

int main() {
    int N;
    printf("Escreve um numero ai: ");
    scanf("%d", &N);

    printf("O resultado da serie ate 1/%d eh: %.6f\n", N, calculoDivisao(N));

    return 0;
}
