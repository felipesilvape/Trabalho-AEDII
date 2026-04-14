#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Criar uma LinkedList
// 2. Definir os tipos de dados (int e  string) 
// 3. Criar as funções da Lista
// 4. Adicionar as funções de ordenação (Selection, Merge e Quick Sort)
// 5. Criar script gerador de dados
// 6. Criar um arquivo similar em Java


typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
Node* chain = NULL;

Node* createList(int value) {
    Node* list = (Node*)malloc(sizeof(Node));

    if(list == NULL) {
        printf("\nFalha ao alocar\n");
        return NULL;
    }

    list->data = value;
    list->next = NULL;

    head = chain = list;
    return list;
}

Node* insert(Node* list, int value) {
    if(head == NULL) return createList(value);

    Node* p = (Node*)malloc(sizeof(Node));

}


int main(int argc, char * argv[]) {


    return 0;
}