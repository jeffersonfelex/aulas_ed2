/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Programa principal que permite ao usuário inserir, exibir e remover
              elementos de uma árvore binária de busca, utilizando remoção por
              cópia ou por fusão.
*/

#include <stdio.h>
#include "no.h"

int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n=== MENU ÁRVORE BINÁRIA ===\n");
        printf("1 - Inserir valor\n");
        printf("2 - Exibir em ordem\n");
        printf("3 - Remover por cópia\n");
        printf("4 - Remover por fusão\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        } 
        else {
            if (opcao == 2) {
                printf("Árvore em ordem: ");
                exibirEmOrdem(raiz);
                printf("\n");
            } 
            else {
                if (opcao == 3) {
                    printf("Valor a remover (cópia): ");
                    scanf("%d", &valor);
                    raiz = removerPorCopia(raiz, valor);
                } 
                else {
                    if (opcao == 4) {
                        printf("Valor a remover (fusão): ");
                        scanf("%d", &valor);
                        raiz = removerPorFusao(raiz, valor);
                    } 
                    else {
                        if (opcao == 0) {
                            printf("Encerrando programa...\n");
                        } 
                        else {
                            printf("Opção inválida!\n");
                        }
                    }
                }
            }
        }

    } while (opcao != 0);

    return 0;
}
