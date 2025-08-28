/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que realiza a multiplicação de dois números
   através de somas sucessivas usando recursão.
*/
#include <stdio.h>

int multiplicacao(int a, int b) {
    if (b == 0) return 0;
    return a + multiplicacao(a, b - 1);
}

int main() {
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    printf("%d x %d = %d\n", a, b, multiplicacao(a, b));
    return 0;
}
