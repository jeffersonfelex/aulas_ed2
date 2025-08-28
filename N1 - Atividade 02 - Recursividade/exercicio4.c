/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Programa que utiliza recursão para imprimir o N-ésimo da sequência Fibonacci
*/

#include <stdio.h>
int fibonacci(int n){
    if (n == 0) {
        return 0;
    }
    
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
    
}
int main()
{
    int N;
    printf("Escreve um numero ai: ");
    scanf("%d", &N);
    printf("O resultado do fibonacci é: %d\n", fibonacci(N));
    return 0;
}