/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que calcula o MDC entre dois números usando recursão.
*/
#include <stdio.h>

int mdc(int x, int y) {
    if (x >= y && x % y == 0) return y;
    if (x < y) return mdc(y, x);
    return mdc(y, x % y);
}

int main() {
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    return 0;
}
