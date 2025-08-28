/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Programa que utiliza recursão para imprimir todos os números naturais de 0 até N em ordem decrecente.
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
    printf("%d ", num_inteiro);
    imprimeNumeros(num_inteiro - 1);
}


int main(){
    int N;
    printf("Fala um número inteiro ai paizão: ");
    scanf("%d", &N);
    imprimeNumeros(N);
    printf("\n");
    
}