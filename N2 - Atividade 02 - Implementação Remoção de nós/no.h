/*
 - Nome: Jefferson Felex de Faria
 - Data: 28/08/2025
 - Descrição: Arquivo de cabeçalho com a estrutura de nó e protótipos das funções
*/

#ifndef NO_H
#define NO_H

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;


No* novoNo(int valor);
No* inserir(No* raiz, int valor);
void exibirEmOrdem(No* raiz);
No* removerPorCopia(No* raiz, int valor);
No* removerPorFusao(No* raiz, int valor);

#endif
