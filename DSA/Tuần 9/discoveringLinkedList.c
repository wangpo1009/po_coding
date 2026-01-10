#include <stdio.h>
#include <stdlib.h>


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
    return;
  }
  
  Node* current = list->head;
  while(current != NULL){
    Node* temp = current->next;
    free(current);
    current = temp;
  }
  list->head = NULL;
}


Node* createNode(int inVal){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = inVal;
  newNode->next = NULL;
  return newNode;
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

//========================== INSERT ==============================
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

void insertHeadList(LinkedList* list, int inputVal){
  Node* newNode = createNode(inputVal);
  
  if(list->head == NULL){
    list->head = newNode;
  }
  
  newNode->next = list->head;
  list->head = newNode;
}

//Assume that all the input val is valid
void insertAtPos(LinkedList* list, int pos, int inputVal){
  Node* newNode = createNode(inputVal);
  
  if(list->head == NULL){
    list->head = newNode;
    return;
  }
  
  int i = 0;
  Node* current = list->head;
  while(i + 1 < pos){
    if(current == NULL){
      printf("Invalid position!\n");
      return ;
    }
    current = current->next;
    i++;
  }
  
  newNode->next = current->next;
  current->next = newNode;
  
}
//========================== DELETE ==============================
void deleteHead(LinkedList* list){
  if(list->head == NULL) return;
  
  Node* temp = list->head;
  list->head = list->head->next;
  free(temp);
  
}

void deleteAtPos(LinkedList* list, int pos){
  if(list->head == NULL) return;
  
  int i = 0;
  Node* current = list->head;
  while( i + 1 < pos){
    if(current == NULL){
      printf("Invalid position!\n");
      return;
    }
    
    current = current->next;
    i++;
  }
  
  Node* temp = current->next;
  current->next = temp->next;
  free(temp);
}

int main(){
  LinkedList list;
  initList(&list);
  
  for(int i = 9; i >= 0; i--){
    insertEndList(&list, i);
  }
  printList(&list);
  
  insertHeadList(&list, 15);
  printList(&list);
  
  deleteHead(&list);
  printList(&list);
  
  insertAtPos(&list, 2, 10);
  printList(&list);
  
  deleteAtPos(&list, 2);
  printList(&list);
  freeList(&list);
  return 0;
}

/*
List: 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 15 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 9 -> 8 -> 10 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
List: 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL
*/


