/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que calcula o N-ésimo termo da sequência de Padovan.
*/
#include <stdio.h>

int padovan(int n) {
    if (n == 0 || n == 1 || n == 2) return 1;
    return padovan(n - 2) + padovan(n - 3);
}

int main() {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);
    printf("Padovan(%d) = %d\n", n, padovan(n));
    return 0;
}
