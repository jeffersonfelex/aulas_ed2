
/*
 - Nome: Jefferson Felex de Faria
 - Data: 30/09/2025
 - Descrição: Programa que preenche, vê, consulta max e min de uma arvore
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    Node* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n###############################\n");
        printf(" [Selecione uma operacao fessor]\n");
        printf(" 1 - Insert Node\n");
        printf(" 2 - Breadth Search (Busca em largura)\n");
        printf(" 3 - Verify item\n");
        printf(" 4 - Get MIN / MAX\n");
        printf(" 5 - Exit\n");
        printf("###############################\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) 
        {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;

            case 2:
                printf("BFS: ");
                bfs(raiz);
                break;

            case 3:
            
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor))
                {
                    printf("Item %d encontrado!\n", valor);

                }
                else
                {
                    printf("Item %d nao encontrado!\n", valor);
                }
                break;

            case 4:
            
                printf("MIN = %d\n", encontrarMin(raiz));
                printf("MAX = %d\n", encontrarMax(raiz));
                break;

            case 5:
                printf("tchau tchau fessor :)\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
