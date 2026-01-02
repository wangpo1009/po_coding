#include <stdio.h>
#include <stdlib.h>
//problem: implement a stack alike list with some function pop, push, print.
typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct stackList{
  node* top;
}stackList;

node* createNode(int val){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

void freeList(stackList* list){
  node* current = list->top;
  
  while(current != NULL){
    node* temp = current->next;
    free(current);
    current = temp;
  }
  
  list->top = NULL;
}

void initList(stackList* list){
  list->top = NULL;
}

int popList(stackList* list){
  int val = list->top->data;
  list->top = list->top->next;
  return val;
}

void pushList(stackList* list, int val){
  node* newNode = createNode(val);
  newNode->next = list->top;
  list->top = newNode;
}

void printList(stackList* list){
  node* current = list->top;
  
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main(){
  int po[4] = {1, 0, 0, 9};
  stackList list;
  initList(&list);
  
  for(int i = 3; i >= 0; i--){
    pushList(&list, po[i]);
  }
  printf("List after push:");
  printList(&list);
  
  popList(&list);
  printf("List after poping:");
  printList(&list);
  
  freeList(&list);
  return 0;
}
