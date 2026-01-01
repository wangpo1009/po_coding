#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct linkedList{
  node* head;
}linkedList;

void initLinkedList(linkedList* list){
  list->head = NULL;
}

node* createNode(int val){
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

void freeList(linkedList* list){
  node* current = list->head;
  node* nextNode = NULL;
  
  while(current != NULL){
    nextNode = current->next;
    free(current);
    current = nextNode;
  }
  list->head = NULL;
}

void printList(linkedList* list){
  node* current = list->head;
  
  while(current != NULL){
    printf("%d -> ",current->data);
    current = current->next;
  }
  printf("NULL\n");
}

//problem: insert node as the result linked list is in ascending order
//assume the given list is already in ascending order

void insertAscending(linkedList* list, int val){
  node* newNode = createNode(val);
  
  if(list->head == NULL || list->head->data >= val){
    newNode->next = list->head;
    list->head = newNode;
    return;
  }
  
  node* current = list->head;
  
  while(current->data < val && current->next != NULL){
    current = current->next;
  }
  
  newNode->next = current->next;
  current->next = newNode;
}

//problem: delete node as the result list is in ascending order
//assume the given list is already in ascending order
void deleteAscending(linkedList* list, int val){
  if(list->head == NULL){
    printf("Empty list!\n");
    return;
  }
  
  if(val == list->head->data){
    node* temp = list->head;
    list->head = list->head->next;
    free(temp);
  }
  
  node* current = list->head;
  node* prev = NULL;
  
  while(current->next != NULL && current->next->data < val){
    current = current->next;
  }
  
  if(current->next != NULL && current->next->data == val){
    node* temp = current->next;
    current->next = temp->next;
    free(temp);
  } else {
    printf("Can't find the element %d!\n", val);
  }
}

int main(){
  int po[5] = {2, -5, 10, -12, 17};
  linkedList list;
  initLinkedList(&list);
  
  for(int i = 0; i < 5; i++){
    insertAscending(&list, po[i]);
  }
  printList(&list);
  
  deleteAscending(&list, 5);
  printList(&list);
  freeList(&list);
  
 return 0; 
}
