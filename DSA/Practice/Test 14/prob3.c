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


void printListBackward(LinkedList *list){
  if(list->head == NULL){
    printf("List is empty!\n");
    return;
  }
  printf("NULL ");
  printList(list->head);
  
}

void printList(Node *current){
  if(current == NULL){
    return ;
  }
  
  printList(current->next);
  printf(" <- %d ", current->data);
  
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



int main(){
  LinkedList list;
  initList(&list);
  
  for(int i = 9; i >= 0; i--){
    insertEndList(&list, i);
  }
  printListBackward(&list);
  
  freeList(&list);
  return 0;
}
//NULL  <- 0  <- 1  <- 2  <- 3  <- 4  <- 5  <- 6  <- 7  <- 8  <- 9

