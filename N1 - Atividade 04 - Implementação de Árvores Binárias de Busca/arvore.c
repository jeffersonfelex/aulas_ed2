#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Cria um novo nó
Node* novoNo(int valor) 
{
    Node* no = (Node*)malloc(sizeof(Node));
    no->valor = valor;
    no->esq = no->dir = NULL;
    return no;
}

// Insere nó na árvore
Node* inserir(Node* raiz, int valor) 
{
    if (raiz == NULL) return novoNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

// Busca em largura (BFS)
void bfs(Node* raiz) 
{
    if (raiz == NULL) 
    {
        printf("Arvore vazia!\n");
        return;
    }

    Node* fila[100];
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;

    while (inicio < fim) 
    {
        Node* atual = fila[inicio++];
        printf("%d ", atual->valor);

        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
    printf("\n");
}

// Verifica se um valor existe na árvore
int buscar(Node* raiz, int valor) 
{
    if (raiz == NULL) return 0;
    if (raiz->valor == valor)
    { 
        return 1;
    }
    if (valor < raiz->valor)
    {
        return buscar(raiz->esq, valor);
    }
    else
    {
        return buscar(raiz->dir, valor);

    }
}

// Retorna o menor valor
int encontrarMin(Node* raiz) 
{
    if (raiz == NULL) return -1;
    while (raiz->esq != NULL) raiz = raiz->esq;
    return raiz->valor;
}

// Retorna o maior valor
int encontrarMax(Node* raiz) 
{
    if (raiz == NULL)
    {
        return -1;
    }
    while (raiz->dir != NULL)
    {
        raiz = raiz->dir;
    }
    return raiz->valor;
}
