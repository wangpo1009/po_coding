
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct LinkedList{
  Node* head;
}LinkedList;


void initList(LinkedList* list){
  list->head = NULL;
}

void freeList(LinkedList* list){
  if(list->head == NULL){
    return ;
  }
  
  Node* current = list->head;
  while(current != NULL){
    Node* temp = current->next;
    free(current);
    current = temp;
  }
  
  list->head = NULL;
}

Node* createNode(int val){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

//insert linked list using recursion
void insertAtPosition(LinkedList* list, Node* current, int pos, int val){
    if(current == NULL){
        printf("Invalid position!\n");
        return;
    }
    
    Node* newNode = createNode(val);
    if(pos == 0){
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    
    if(pos - 1 == 0){
        newNode->next = current->next;
        current->next = newNode;
        return;
    }

    insertAtPosition(list, current->next, pos-1, val);
}

void insertEndList(LinkedList* list, int inputVal){
  
  if(list->head == NULL){
    list->head = createNode(inputVal);
    return;
  }
  
  Node* current = list->head;
  while( current->next != NULL ){
    current = current->next;
  }
  current->next = createNode(inputVal);
  
}

//delete node using recursion
void deleteAtPosition(LinkedList* list, Node* current, int pos){
  if(list->head == NULL){
    printf("Invalid Position!\n");
    return;
  }
  
  if( pos == 0 ){
    Node* temp = list->head;
    list->head = temp->next;
    free(temp);
    return;
  }
  
  if(current == NULL || current->next == NULL){
    printf("Invalid position!\n");
    return;
  }

  if( pos == 1 ){
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return;
  }
  
  deleteAtPosition(list, current->next, pos-1);
  
}

void printList(LinkedList* list){
  if(list->head == NULL){
    printf("List is empty!\n");
    return;
  }
  
  printf("List: ");
  Node* current = list->head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}


int main(){
  LinkedList list;
  initList(&list);
  
  for(int i = 9; i >= 0; i--){
    insertEndList(&list, i);
  }
  printList(&list);
  
  insertAtPosition(&list, list.head, 0, 10);
  printList(&list);
  
  deleteAtPosition(&list, list.head, 10);
  printList(&list);
  return 0;
}

/*
List: 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/





