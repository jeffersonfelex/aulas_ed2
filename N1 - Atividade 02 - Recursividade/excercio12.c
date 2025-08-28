/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que calcula o N-ésimo termo da sequência de Tribonacci.
*/
#include <stdio.h>

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);
    printf("Tribonacci(%d) = %d\n", n, tribonacci(n));
    return 0;
}
