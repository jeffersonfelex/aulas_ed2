/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Implementa as funções principais da árvore binária de busca (ABB),
              incluindo inserção, exibição e remoção por cópia e por fusão.
*/

#include <stdio.h>
#include <stdlib.h>
#include "no.h"


No* novoNo(int valor) {
    No* temp = (No*) malloc(sizeof(No));
    temp->valor = valor;
    temp->esq = temp->dir = NULL;
    return temp;
}


No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    } 
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } 
    else {
        if (valor > raiz->valor) {
            raiz->dir = inserir(raiz->dir, valor);
        }
    }
    return raiz;
}

void exibirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->dir);
    }
}


No* maiorNo(No* raiz) {
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz;
}


No* removerPorCopia(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esq = removerPorCopia(raiz->esq, valor);
    } 
    else {
        if (valor > raiz->valor) {
            raiz->dir = removerPorCopia(raiz->dir, valor);
        } 
        else {
            if (raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                return NULL;
            } 
            else {
                if (raiz->esq == NULL) {
                    No* temp = raiz->dir;
                    free(raiz);
                    return temp;
                } 
                else {
                    if (raiz->dir == NULL) {
                        No* temp = raiz->esq;
                        free(raiz);
                        return temp;
                    } 
                    else {
                        No* temp = maiorNo(raiz->esq);
                        raiz->valor = temp->valor;
                        raiz->esq = removerPorCopia(raiz->esq, temp->valor);
                    }
                }
            }
        }
    }
    return raiz;
}


No* removerPorFusao(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    
    if (valor < raiz->valor) {
        raiz->esq = removerPorFusao(raiz->esq, valor);
    } 
    else {
        if (valor > raiz->valor) {
            raiz->dir = removerPorFusao(raiz->dir, valor);
        } 
        else {
            if (raiz->esq == NULL) {
                No* temp = raiz->dir;
                free(raiz);
                return temp;
            } 
            else {
                if (raiz->dir == NULL) {
                    No* temp = raiz->esq;
                    free(raiz);
                    return temp;
                } 
                else {
                    No* temp = raiz->esq;
                    No* maior = temp;
                    while (maior->dir != NULL) {
                        maior = maior->dir;
                    }
                    maior->dir = raiz->dir;
                    free(raiz);
                    return temp;
                }
            }
        }
    }
    return raiz;
}
