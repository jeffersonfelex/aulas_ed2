/*
 - Nome: Jefferson Felex de Faria
 - Data: 15/09/2025
 - Descrição: Programa que implementa uma tabela hash para armazenar alunos,
              permitindo inserção, remoção e exibição dos dados.
*/

#include "Aluno.h"
#include "HashTable.h"
#include <stdio.h>

/*
    Definição do tamanho da tabela hash
*/
#define TABLE_SIZE 10

int main() {
    // Array de alunos fixo
    Aluno dados[TABLE_SIZE];
    
    // Criação da tabela hash
    HashTable ht;

    // Inicializa a tabela hash com TABLE_SIZE baldes
    initHashTable(&ht, TABLE_SIZE);

    // Entrada de dados dos alunos
    for (int i = 0; i < TABLE_SIZE; i++) {
        char nome[MAX_NOME];
        long int mat;

        printf("Digite o nome %d: ", i);
        scanf("%s", nome);

        printf("Digite a matricula %d: ", i);
        scanf("%ld", &mat);

        // Inicializa o aluno com matrícula e nome
        setAluno(&dados[i], mat, nome);

        // Insere o aluno na tabela hash
        insertItem(&ht, &dados[i]);
    }

    // Inserção de um aluno específico
    Aluno aluno;
    setAluno(&aluno, 2014, "Jose");
    insertItem(&ht, &aluno);

    // Exibição da tabela hash
    displayHashTable(&ht);

    // Remoção do aluno específico
    deleteItem(&ht, &aluno);

    // Exibição da tabela hash após remoção
    displayHashTable(&ht);

    // Liberação da memória alocada pela tabela hash
    destruirHashTable(&ht);

    return 0;
}
