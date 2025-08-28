/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que realiza a soma de dois números
   através de incrementos sucessivos usando recursão.
*/
#include <stdio.h>

int soma(int a, int b) {
    if (b == 0) return a;
    return soma(a + 1, b - 1);
}

int main() {
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, soma(a, b));
    return 0;
}
