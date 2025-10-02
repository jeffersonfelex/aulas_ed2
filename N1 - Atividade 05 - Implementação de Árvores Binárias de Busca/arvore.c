#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Estrutura de pilha (para DFS iterativo)
typedef struct Stack 
{
    Node* data[100];
    int topo;
} Stack;

void push(Stack* s, Node* no) 
{
    s->data[++s->topo] = no;
}
Node* pop(Stack* s) 
{
    return s->data[s->topo--];
}
int isEmpty(Stack* s) 
{
    return s->topo == -1;
}

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
    if (raiz == NULL) 
    {
        return novoNo(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else 
    {
        if (valor > raiz->valor)
        {
            raiz->dir = inserir(raiz->dir, valor);
        }
    }
    return raiz;
}

// BFS - busca em largura
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
        if (atual->esq)
        {
            fila[fim++] = atual->esq;
        } 
        if (atual->dir)
        {
            fila[fim++] = atual->dir;
        } 
    }
    printf("\n");
}

// Busca valor
int buscar(Node* raiz, int valor)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (raiz->valor == valor)
    {
        return 1;
    } 
    if (valor < raiz->valor)
    {
        return buscar(raiz->esq, valor);
    } 
    return buscar(raiz->dir, valor);
}

// Min e Max
int encontrarMin(Node* raiz) 
{
    if (raiz == NULL)
    {
        return -1;
    } 
    while (raiz->esq)
    {
        raiz = raiz->esq;
    }
    return raiz->valor;
}

int encontrarMax(Node* raiz) 
{
    if (raiz == NULL)
    {
        return -1;
    } 
    while (raiz->dir)
    {
        raiz = raiz->dir;
    }
    return raiz->valor;
}

// -----------------------------
// DFS Recursivos
void inOrder(Node* raiz) 
{
    if (raiz) 
    {
        inOrder(raiz->esq);
        printf("%d ", raiz->valor);
        inOrder(raiz->dir);
    }
}

void preOrder(Node* raiz) 
{
    if (raiz) 
    {
        printf("%d ", raiz->valor);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

void posOrder(Node* raiz) 
{
    if (raiz) 
    {
        posOrder(raiz->esq);
        posOrder(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

// -----------------------------
// DFS Iterativos

void inOrderIterativo(Node* raiz) 
{
    Stack s = {.topo = -1};
    Node* atual = raiz;

    while (atual || !isEmpty(&s)) 
    {
        while (atual) 
        {
            push(&s, atual);
            atual = atual->esq;
        }
        atual = pop(&s);
        printf("%d ", atual->valor);
        atual = atual->dir;
    }
    printf("\n");
}

void preOrderIterativo(Node* raiz) 
{
    if (!raiz)
    {
        return;
    }
    Stack s = {.topo = -1};
    push(&s, raiz);

    while (!isEmpty(&s)) 
    {
        Node* atual = pop(&s);
        printf("%d ", atual->valor);

        if (atual->dir)
        {
            push(&s, atual->dir);
        } 
        if (atual->esq)
        {
            push(&s, atual->esq);
        } 
    }
    printf("\n");
}

void posOrderIterativo(Node* raiz) 
{
    if (!raiz)
    {
        return;
    }
    Stack s1 = {.topo = -1}, s2 = {.topo = -1};

    push(&s1, raiz);
    while (!isEmpty(&s1)) 
    {
        Node* atual = pop(&s1);
        push(&s2, atual);

        if (atual->esq)
        {
            push(&s1, atual->esq);
        } 
        if (atual->dir)
        {
            push(&s1, atual->dir);
        } 
    }

    while (!isEmpty(&s2)) 
    {
        printf("%d ", pop(&s2)->valor);
    }
    printf("\n");
}
