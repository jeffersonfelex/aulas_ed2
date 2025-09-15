#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura Node:
    Cada nó da lista encadeada representa um aluno armazenado
    na tabela hash e aponta para o próximo nó
    (usado para colisões)
*/
typedef struct Node {
    Aluno* aluno;        // ponteiro para o aluno
    struct Node* prox;   // próximo nó da lista
} Node;

/*
    Estrutura HashTable:
    - tamanhoTabela: número de posições da tabela
    - tabela: array de ponteiros para listas encadeadas (baldes)
*/
typedef struct {
    int tamanhoTabela;
    Node** tabela;
} HashTable;

/*
    Função initHashTable:
    Inicializa a tabela hash alocando memória para os baldes
    e definindo cada balde como NULL
*/
void initHashTable(HashTable *ht, int tamanho) {
    ht->tamanhoTabela = tamanho;
    ht->tabela = (Node**)malloc(tamanho * sizeof(Node*));
    for (int i = 0; i < tamanho; i++)
        ht->tabela[i] = NULL;
}

/*
    Função hashFunction:
    Calcula o índice da tabela a partir da matrícula do aluno
    usando o operador módulo para distribuir uniformemente
*/
int hashFunction(HashTable* ht, long int matricula) {
    return matricula % ht->tamanhoTabela;
}

/*
    Função insertItem:
    Insere um aluno na tabela hash.
    - Cria um novo nó
    - Insere no início da lista do balde correspondente
*/
void insertItem(HashTable* ht, Aluno* aluno) {
    int indice = hashFunction(ht, aluno->matricula);
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->aluno = aluno;
    novo->prox = ht->tabela[indice];
    ht->tabela[indice] = novo;
}

/*
    Função deleteItem:
    Remove um aluno da tabela hash usando a matrícula como chave
    - Percorre a lista do balde
    - Ajusta ponteiros para remover o nó
    - Libera memória do nó removido
*/
void deleteItem(HashTable* ht, Aluno* aluno) {
    int indice = hashFunction(ht, aluno->matricula);
    Node* atual = ht->tabela[indice];
    Node* anterior = NULL;

    while (atual != NULL) {
        if (atual->aluno->matricula == aluno->matricula) {
            if (anterior == NULL)
                ht->tabela[indice] = atual->prox;
            else
                anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

/*
    Função displayHashTable:
    Exibe todos os baldes da tabela hash e os alunos armazenados
    em cada balde (com matrícula e nome)
*/
void displayHashTable(HashTable* ht) {
    printf("\nTabela Hash:\n");
    for (int i = 0; i < ht->tamanhoTabela; i++) {
        printf("%d", i);
        Node* atual = ht->tabela[i];
        while (atual != NULL) {
            printf(" -> [%ld, %s]", atual->aluno->matricula, atual->aluno->nome);
            atual = atual->prox;
        }
        printf("\n");
    }
}

/*
    Função destruirHashTable:
    Libera toda a memória alocada pela tabela hash
    - Percorre todos os baldes e libera os nós
    - Libera o array da tabela
*/
void destruirHashTable(HashTable* ht) {
    for (int i = 0; i < ht->tamanhoTabela; i++) {
        Node* atual = ht->tabela[i];
        while (atual != NULL) {
            Node* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(ht->tabela);
}

#endif // HASHTABLE_H
