#include <stdio.h>
#include <stdlib.h>

#define MAX 255

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
}

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeList(LinkedList* list){
    Node* current = list->head;
    Node* nextNode;
    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
}

void printList(LinkedList* list){
    Node* current = list->head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertAtHead(LinkedList* list, int data){
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtTail(LinkedList* list, int data){
    Node* newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAtLocation(LinkedList* list, int pos, int data){
    Node* newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    for(int i = 0; i < pos - 2; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(LinkedList* list, int data){
    Node* current = list->head;
    Node* prev = NULL;
    while(current != NULL){
        if(current->data == data){
            if(prev == NULL){
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void deleteAtPosition(LinkedList* list, int pos){
    if(list->head == NULL) return;

    Node* current = list->head;
    Node* prev = NULL;

    for(int i = 0; i < pos; i++){
        if(current == NULL) return;
        prev = current;
        current = current->next;
    }

    if(prev == NULL){
        list->head = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);
}


int main(){
    LinkedList list;
    initList(&list);
    for(int i = 0; i < 10; i++){
        Node* newNode = createNode(i);
        newNode->next = list.head;
        list.head = newNode;
    }
    printf("Ex1: insertAtAlocation & deleteAtPosition\n");
    printf("Initial List:\n");
    printList(&list);
    insertAtLocation(&list, 3, 11);
    printf("After inserting 11 at position 3:\n");
    printList(&list);
    deleteAtPosition(&list, 4);
    printf("After deleting node at position 4:\n");
    printList(&list);
    freeList(&list);
    
    
    int po[8] = {2, 12, 9, 0, 11, 3, 4, 8};
    for(int i = 0; i < 8; i++){
        insertAtTail(&list, po[i]);
    }
    insertAtHead(&list, 19);
    insertAtTail(&list,-3);
    printList(&list);


    deleteNode(&list, -3);
    deleteNode(&list, 19);
    printList(&list);
    freeList(&list);
    return 0;
}
//19 -> 2 -> 12 -> 9 -> 0 -> 11 -> 3 -> 4 -> 8 -> -3 -> NULL
//2 -> 12 -> 9 -> 0 -> 11 -> 3 -> 4 -> 8 -> NULL
