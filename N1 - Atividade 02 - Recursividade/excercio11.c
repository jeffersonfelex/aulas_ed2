/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que calcula k^n de forma recursiva usando apenas multiplicações.
*/
#include <stdio.h>

int potencia(int k, int n) {
    if (n == 0) return 1;
    return k * potencia(k, n - 1);
}

int main() {
    int k, n;
    printf("Digite k e n: ");
    scanf("%d %d", &k, &n);
    printf("%d^%d = %d\n", k, n, potencia(k, n));
    return 0;
}
