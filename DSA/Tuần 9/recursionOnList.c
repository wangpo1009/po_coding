#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node{
  int data;
  struct node* next;
}next;

typedef struct linkedList{
  node* head;
}linkedList;


void initList(linkedList* list){
  list->head = NULL;
}

void freeList(linkedList* list){
  if(list->head == NULL){
    return ;
  }
  
  node* current = list->head;
  while(current != NULL){
    node* temp = current->next;
    free(current);
    current = temp;
  }
  
  list->head = NULL;
}

node* createNode(int val){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

//insert linked list using recursion
void insertAtPosition(linkedList* list, int pos, int val, int n){
  if(list->head == NULL && pos != 0){
    printf("Invalid position!\n");
    return;
  }
  
  if(list->head == NULL){
    node* newNode = createNode(val);
    list->head = newNode;
    return;
  }
  
  if(n == pos-1){
    node* current
  }
  node* current = list->head;
  
  
}



int main(){
  
  return 0;
}
