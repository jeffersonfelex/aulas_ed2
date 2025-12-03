#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char texto[200];
    char opcaoA[100];
    char opcaoB[100];
    char correta;
    int proxIdAcerto;
    int proxIdErro;
} Pergunta;

typedef struct No {
    Pergunta dado;
    struct No *esquerda;
    struct No *direita;
    int altura;
} No;

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int altura(No *N) {
    if (N == NULL) return 0;
    return N->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

No* novoNo(Pergunta p) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = p;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1; 
    return no;
}

No *rotacaoDireita(No *y) {
    No *x = y->esquerda;
    No *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No *rotacaoEsquerda(No *x) {
    No *y = x->direita;
    No *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int getBalanceamento(No *N) {
    if (N == NULL) return 0;
    return altura(N->esquerda) - altura(N->direita);
}

No* inserir(No* no, Pergunta p) {
    if (no == NULL) return novoNo(p);

    if (p.id < no->dado.id)
        no->esquerda = inserir(no->esquerda, p);
    else if (p.id > no->dado.id)
        no->direita = inserir(no->direita, p);
    else 
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balance = getBalanceamento(no);

    if (balance > 1 && p.id < no->esquerda->dado.id)
        return rotacaoDireita(no);

    if (balance < -1 && p.id > no->direita->dado.id)
        return rotacaoEsquerda(no);

    if (balance > 1 && p.id > no->esquerda->dado.id) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balance < -1 && p.id < no->direita->dado.id) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

No* buscar(No* raiz, int id) {
    if (raiz == NULL || raiz->dado.id == id)
        return raiz;

    if (raiz->dado.id < id)
        return buscar(raiz->direita, id);

    return buscar(raiz->esquerda, id);
}

No *minValorNo(No *no) {
    No *atual = no;
    while (atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

No* remover(No* raiz, int id) {
    if (raiz == NULL) return raiz;

    if (id < raiz->dado.id)
        raiz->esquerda = remover(raiz->esquerda, id);
    else if (id > raiz->dado.id)
        raiz->direita = remover(raiz->direita, id);
    else {
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
            No *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            free(temp);
        } else {
            No *temp = minValorNo(raiz->direita);
            raiz->dado = temp->dado;
            raiz->direita = remover(raiz->direita, temp->dado.id);
        }
    }

    if (raiz == NULL) return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
    int balance = getBalanceamento(raiz);

    if (balance > 1 && getBalanceamento(raiz->esquerda) >= 0)
        return rotacaoDireita(raiz);

    if (balance > 1 && getBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && getBalanceamento(raiz->direita) <= 0)
        return rotacaoEsquerda(raiz);

    if (balance < -1 && getBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void salvarArquivoAux(No* raiz, FILE* f) {
    if (raiz != NULL) {
        fprintf(f, "%d;%s;%s;%s;%c;%d;%d\n", 
            raiz->dado.id, raiz->dado.texto, raiz->dado.opcaoA, 
            raiz->dado.opcaoB, raiz->dado.correta, 
            raiz->dado.proxIdAcerto, raiz->dado.proxIdErro);
        salvarArquivoAux(raiz->esquerda, f);
        salvarArquivoAux(raiz->direita, f);
    }
}

void salvarBanco(No* raiz) {
    FILE *f = fopen("perguntas.txt", "w");
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }
    salvarArquivoAux(raiz, f);
    fclose(f);
    printf("Dados salvos com sucesso!\n");
}

No* carregarBanco() {
    FILE *f = fopen("perguntas.txt", "r");
    No* raiz = NULL;
    if (!f) return NULL;

    Pergunta p;
    while (fscanf(f, "%d;%[^;];%[^;];%[^;];%c;%d;%d\n", 
           &p.id, p.texto, p.opcaoA, p.opcaoB, &p.correta, 
           &p.proxIdAcerto, &p.proxIdErro) != EOF) {
        raiz = inserir(raiz, p);
    }
    fclose(f);
    return raiz;
}

void salvarRanking(char* nome, int pontos) {
    FILE *f = fopen("ranking.txt", "a");
    if (f) {
        fprintf(f, "%s;%d\n", nome, pontos);
        fclose(f);
    }
}

void exibirRanking() {
    FILE *f = fopen("ranking.txt", "r");
    char nome[50];
    int pontos;
    
    printf("\n--- RANKING ---\n");
    if (!f) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    while (fscanf(f, "%[^;];%d\n", nome, &pontos) != EOF) {
        printf("Jogador: %-15s | Pontos: %d\n", nome, pontos);
    }
    fclose(f);
    printf("-----------------\n");
}

void cadastrarPergunta(No **raiz) {
    Pergunta p;
    printf("\n--- Cadastro de Pergunta ---\n");
    printf("ID (Numero unico): ");
    scanf("%d", &p.id);
    getchar();

    if (buscar(*raiz, p.id) != NULL) {
        printf("Erro: ID ja existe!\n");
        return;
    }

    printf("Texto da Pergunta: ");
    scanf(" %[^\n]", p.texto);
    printf("Opcao A: ");
    scanf(" %[^\n]", p.opcaoA);
    printf("Opcao B: ");
    scanf(" %[^\n]", p.opcaoB);
    printf("Opcao Correta (A/B): ");
    scanf(" %c", &p.correta);
    printf("Prox. ID se acertar (0 para FIM): ");
    scanf("%d", &p.proxIdAcerto);
    printf("Prox. ID se errar (0 para FIM): ");
    scanf("%d", &p.proxIdErro);

    *raiz = inserir(*raiz, p);
    salvarBanco(*raiz);
}

void jogar(No *raiz) {
    if (raiz == NULL) {
        printf("Banco de perguntas vazio. Cadastre perguntas primeiro.\n");
        return;
    }

    char nome[50];
    printf("Digite seu nome: ");
    scanf(" %[^\n]", nome);

    int idAtual;
    printf("Digite o ID da primeira pergunta para começar: ");
    scanf("%d", &idAtual);

    int pontuacao = 0;
    
    while (idAtual != 0) {
        No* no = buscar(raiz, idAtual);
        
        if (no == NULL) {
            printf("Erro: Pergunta ID %d nao encontrada. Jogo encerrado.\n", idAtual);
            break;
        }

        printf("\n------------------------------------------------\n");
        printf("PERGUNTA: %s\n", no->dado.texto);
        printf("[A] %s\n", no->dado.opcaoA);
        printf("[B] %s\n", no->dado.opcaoB);
        printf("------------------------------------------------\n");
        
        char resp;
        printf("Sua resposta (A/B): ");
        scanf(" %c", &resp);

        if (resp >= 'a' && resp <= 'z') resp -= 32;

        if (resp == no->dado.correta) {
            printf(">> RESPOSTA CORRETA!\n");
            pontuacao += 10;
            idAtual = no->dado.proxIdAcerto;
        } else {
            printf(">> RESPOSTA INCORRETA!\n");
            idAtual = no->dado.proxIdErro;
        }
    }

    printf("\nFIM DE JOGO!\n");
    printf("Pontuacao Final de %s: %d\n", nome, pontuacao);
    salvarRanking(nome, pontuacao);
}

void menu(No **raiz) {
    int op = 0;
    while(op != 4) {
        printf("\n--- MENU ---\n");
        printf("1. Inserir Pergunta\n");
        printf("2. Remover Pergunta\n");
        printf("3. Listar (Ordem ID)\n");
        printf("4. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            cadastrarPergunta(raiz);
        } else if (op == 2) {
            int id;
            printf("ID para remover: ");
            scanf("%d", &id);
            *raiz = remover(*raiz, id);
            salvarBanco(*raiz);
            printf("Removido (se existia) e salvo.\n");
        } else if (op == 3) {
            printf("Recurso para visualizar o arquivo 'perguntas.txt'.\n");
        }
    }
}

int main() {
    No *raiz = carregarBanco();
    int op = 0;

    printf("--- QUIZ GAME AVL ---\n");
    
    if (raiz == NULL) {
        printf("AVISO: Banco de dados vazio ou inexistente.\n");
    }

    while (op != 4) {
        printf("\n1. Jogue\n");
        printf("2. Ranking\n");
        printf("3. Gerenciar Perguntas\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: jogar(raiz); break;
            case 2: exibirRanking(); break;
            case 3: menu(&raiz); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    }

    return 0;
}