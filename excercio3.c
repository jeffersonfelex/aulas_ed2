/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Programa que utiliza recursão para calcular o valor fatorial de um número inteiro
*/

#include <stdio.h>

int fatorial(int num_inteiro){
    if(num_inteiro == 0 || num_inteiro == 1){
        return 1;
    }

    return num_inteiro * fatorial(num_inteiro - 1);
}

int main(){
    int N;
    printf("Fala um número inteiro ai paizão: ");
    scanf("%d", &N);
    printf("O resultado fatorial é: %d\n", fatorial(N));
}