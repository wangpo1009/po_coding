#include <stdio.h>
#include <stdlib.h>
//problem: implement a queue alike list with some function get, put, print.
typedef struct node{
  int data;
  struct node* next;
  struct node* prev;
}node;

typedef struct queueList{
  node* head;
  node* tail;
}queueList;

node* createNode(int val){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void freeList(queueList* list){
  node* current = list->head;
  
  while(current != NULL){
    node* temp = current->next;
    free(current);
    current = temp;
  }
  
  list->head = NULL;
  list->tail = NULL;
}

void initList(queueList* list){
  list->head = NULL;
  list->tail = NULL;
}

void putList(queueList* list, int data){
  node* newNode = createNode(data);

  if(list->tail == NULL){
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  newNode->prev = list->tail;
  list->tail->next = newNode;
  list->tail = newNode;
}
//note: remember to free any deleted node
int getList(queueList* list){
  if(list->tail == NULL && list->head == NULL){
    printf("List is empty!\n");
    return 0;
  }
  node* temp = list->head;
  int val = list->head->data;
  
  if(list->head != NULL){
    list->head->prev = NULL;
  } 
  else {
    list->tail = NULL;
  }

  free(temp);
  return val;
}

int main(){
  
}
