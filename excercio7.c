/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que implementa a função de Ackermann de forma recursiva.
*/
#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    int m, n;
    printf("Digite m e n: ");
    scanf("%d %d", &m, &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}
