/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Programa que utiliza recursão para imprimir todos os números naturais de 0 até N em ordem crescente.
*/

#include <stdio.h>

void imprimeNumeros(int num_inteiro){
    if(num_inteiro < 0){
        printf("Não é numero inteiro");
        return;
    }
    if(num_inteiro == 0){
        printf("0 ");
        return;
    }
    imprimeNumeros(num_inteiro - 1);
    printf("%d ", num_inteiro);
}


int main(){
    int N;
    printf("Fala um número inteiro ai paizão: ");
    scanf("%d", &N);
    imprimeNumeros(N);
    printf("\n");
    
}