#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct linkedList{
  node* head;
}linkedList;

node* createNode(int data){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

void freeList(linkedList* list){
  node* current = list->head;
  
  while(current != NULL){
    node* temp = current->next;
    free(current);
    current = temp;
  }
  
  list->head = NULL;
}


int main(){
  
  return 0;
}
