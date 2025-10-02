
/*
 - Nome: Jefferson Felex de Faria
 - Data: 30/09/2025
 - Descrição: Programa que preenche, vê, consulta max e min de uma arvore
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() 
{
    Node* raiz = NULL;
    int opcao, valor;

    do 
    {
        printf("\n#########################################\n");
        printf(" [Selecione uma operacao ai fessor]\n");
        printf(" 1  - Insert Node\n");
        printf(" 2  - Breadth Search (Busca em largura)\n");
        printf(" 3  - Verify item\n");
        printf(" 4  - Get MIN / MAX\n");
        printf(" 5  - Depth Search (In Order)\n");
        printf(" 6  - Depth Search (Pre Order)\n");
        printf(" 7  - Depth Search (Pos Order)\n");
        printf(" 8  - Depth Search (iterative Pre Order)\n");
        printf(" 9  - Depth Search (iterative Pos Order)\n");
        printf(" 10 - Depth Search (iterative In Order)\n");
        printf(" 11 - Exit\n");
        printf("#########################################\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
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
                    printf("Item %d encontrado!\n", valor);
                else
                    printf("Item %d NAO encontrado!\n", valor);
                break;

            case 4:
                printf("MIN = %d\n", encontrarMin(raiz));
                printf("MAX = %d\n", encontrarMax(raiz));
                break;

            case 5:
                printf("DFS In Order: ");
                inOrder(raiz);
                printf("\n");
                break;

            case 6:
                printf("DFS Pre Order: ");
                preOrder(raiz);
                printf("\n");
                break;

            case 7:
                printf("DFS Pos Order: ");
                posOrder(raiz);
                printf("\n");
                break;

            case 8:
                printf("DFS Iterative Pre Order: ");
                preOrderIterativo(raiz);
                break;

            case 9:
                printf("DFS Iterative Pos Order: ");
                posOrderIterativo(raiz);
                break;

            case 10:
                printf("DFS Iterative In Order: ");
                inOrderIterativo(raiz);
                break;

            case 11:
                printf("Tchau tchau fessor :D...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 11);

    return 0;
}
