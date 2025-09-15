#include "Aluno.h"

/*
    Implementação da função setAluno
    - Recebe um ponteiro para Aluno
    - Define a matrícula
    - Copia o nome usando strncpy para garantir o limite MAX_NOME
    - Garante terminação nula no final do nome
*/
void setAluno(Aluno *aluno, long int matricula, const char *nome) {
    aluno->matricula = matricula;
    strncpy(aluno->nome, nome, MAX_NOME);
    aluno->nome[MAX_NOME - 1] = '\0'; // garante terminação nula
}
