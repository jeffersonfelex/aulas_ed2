#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void breadthSearch(Node* root) {
    if (root == NULL) {
        printf("Arvore vazia!\n");
        return;
    }
    
    Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    printf("Busca em largura: ");
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    printf("\n");
}

int verifyItem(Node* root, int data) {
    if (root == NULL)
        return 0;
    
    if (root->data == data)
        return 1;
    
    if (data < root->data)
        return verifyItem(root->left, data);
    else
        return verifyItem(root->right, data);
}

void clearTree(Node** root) {
    if (*root != NULL) {
        clearTree(&(*root)->left);
        clearTree(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void posOrder(Node* root) {
    if (root != NULL) {
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ", root->data);
    }
}

void printMenu() {
    printf("\n");
    printf("##################################################\n");
    printf("##                                              ##\n");
    printf("##        AVL TREE                              ##\n");
    printf("##        (ARVORE AVL)                          ##\n");
    printf("##                                              ##\n");
    printf("##################################################\n");
    printf("##                                              ##\n");
    printf("##        [Selecione uma operacao]              ##\n");
    printf("##                                              ##\n");
    printf("##  1 - Insert Node                             ##\n");
    printf("##  2 - Breadth Search (Busca em largura)       ##\n");
    printf("##  3 - Verify item                             ##\n");
    printf("##  4 - Clear Tree                              ##\n");
    printf("##  5 - Depth Search (In Order)                 ##\n");
    printf("##  6 - Depth Search (Pre Order)                ##\n");
    printf("##  7 - Depth Search (Pos Order)                ##\n");
    printf("##  8 - Exit                                    ##\n");
    printf("##                                              ##\n");
    printf("##################################################\n");
    printf("\nDigite a opcao: ");
}

int main() {
    Node* root = NULL;
    int option, value;
    
    do {
        printMenu();
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Valor %d inserido com sucesso!\n", value);
                break;
                
            case 2:
                breadthSearch(root);
                break;
                
            case 3:
                printf("Digite o valor a ser verificado: ");
                scanf("%d", &value);
                if (verifyItem(root, value))
                    printf("O valor %d esta na arvore!\n", value);
                else
                    printf("O valor %d NAO esta na arvore!\n", value);
                break;
                
            case 4:
                clearTree(&root);
                printf("Arvore limpa com sucesso!\n");
                break;
                
            case 5:
                printf("Busca em profundidade (In Order): ");
                if (root == NULL)
                    printf("Arvore vazia!");
                else
                    inOrder(root);
                printf("\n");
                break;
                
            case 6:
                printf("Busca em profundidade (Pre Order): ");
                if (root == NULL)
                    printf("Arvore vazia!");
                else
                    preOrder(root);
                printf("\n");
                break;
                
            case 7:
                printf("Busca em profundidade (Pos Order): ");
                if (root == NULL)
                    printf("Arvore vazia!");
                else
                    posOrder(root);
                printf("\n");
                break;
                
            case 8:
                printf("Encerrando programa...\n");
                clearTree(&root);
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while(option != 8);
    
    return 0;
}