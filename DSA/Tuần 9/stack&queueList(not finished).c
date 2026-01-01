#include <stdio.h>
#include <stdlib.h>
//problem: implement a stack alike list with some function insert, delete, print.
typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct stackList{
  node* top;
}stackList;

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

void initList()
int main(){
  
  return 0;
}
