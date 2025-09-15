/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa que soma os elementos de um vetor usando recursão.
*/
#include <stdio.h>

int somaVetor(int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + somaVetor(v, n - 1);
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("Soma dos elementos = %d\n", somaVetor(v, n));
    return 0;
}
