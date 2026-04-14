#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 1. Criar uma LinkedList
// 2. Definir os tipos de dados (int e  string) 
// 3. Criar as funções da Lista
// 4. Adicionar as funções de ordenação (Selection, Merge e Quick Sort)
// 5. Criar script gerador de dados
// 6. Criar um arquivo similar em Java


typedef struct NodeInt {
    int data;
    struct NodeInt* next;
} NodeInt;

NodeInt* createNodeInt(int value) {
    NodeInt* newNode = (NodeInt*)malloc(sizeof(NodeInt));
    if(newNode == NULL) {
        printf("\nErro de alocação de memória\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertInt(NodeInt** head, int value) {
    NodeInt* newNode = createNodeInt(value);

    if(*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Se não, percorre até o final e insere
    NodeInt* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 1. A Struct do Nó de Strings
typedef struct NodeStr {
    char data[50];
    struct NodeStr* next;
} NodeStr;

// 2. Função para criar um novo nó de String
NodeStr* createNodeStr(char* text) {
    NodeStr* newNode = (NodeStr*)malloc(sizeof(NodeStr));
    if (newNode == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    strcpy(newNode->data, text); // Para strings, usamos strcpy em vez de "="
    newNode->next = NULL;
    return newNode;
}

// 3. Função para inserir no final da lista de Strings
void insertStr(NodeStr** head, char* text) {
    NodeStr* newNode = createNodeStr(text);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    NodeStr* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


int main(int argc, char * argv[]) {
    NodeInt* listInt = NULL;
    NodeStr* listStr = NULL;

    FILE* fptr = fopen("dados_teste/inteiros_100.txt", "r");

    if(fptr == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo de inteiros!\n");
        return 1; // Encerra o programa com erro
    }

    int read_value;

    while (fscanf(fptr, "%d", &read_value) == 1) {
        insertInt(&listInt, read_value); // Insere o valor lido na nossa lista
    }
    
    fclose(fptr);
    printf("Arquivo lido e lista de inteiros preenchida com sucesso!\n");


    return 0;
}