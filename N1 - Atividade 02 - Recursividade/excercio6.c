/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que calcula o N-ésimo termo da sequência F definida por:
   F(1)=1, F(2)=2 e F(n)=2*F(n-1)+3*F(n-2).
*/
#include <stdio.h>

int sequencia(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return 2 * sequencia(n - 1) + 3 * sequencia(n - 2);
}

int main() {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);
    printf("F(%d) = %d\n", n, sequencia(n));
    return 0;
}
