#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAX_NOME: tamanho máximo do nome do aluno
#define MAX_NOME 100

/*
    Estrutura do Aluno:
    - matricula: número de matrícula do aluno
    - nome: nome do aluno (string)
*/
typedef struct {
    long int matricula;
    char nome[MAX_NOME];
} Aluno;

/*
    Função setAluno:
    Inicializa os dados do aluno (matricula e nome)
*/
void setAluno(Aluno *aluno, long int matricula, const char *nome);

#endif // ALUNO_H
