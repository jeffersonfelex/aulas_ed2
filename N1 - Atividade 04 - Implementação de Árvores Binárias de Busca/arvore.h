#ifndef ARVORE_H
#define ARVORE_H

typedef struct Node 
{
    int valor;
    struct Node *esq, *dir;
} Node;

    Node* inserir(Node* raiz, int valor);
    void bfs(Node* raiz);
    int buscar(Node* raiz, int valor);
    int encontrarMin(Node* raiz);
    int encontrarMax(Node* raiz);

#endif
