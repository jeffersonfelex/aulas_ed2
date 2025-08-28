/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que inverte um número inteiro usando recursão.
*/
#include <stdio.h>

int inverterNumero(int n, int invertido) {
    if (n == 0) return invertido;
    return inverterNumero(n / 10, invertido * 10 + n % 10);
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Numero invertido: %d\n", inverterNumero(n, 0));
    return 0;
}
