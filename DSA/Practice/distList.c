#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define EPSILON 0.0000001

//============================== STRUCTING ==============================
typedef struct Point{
  float x, y, z;
}Point;

typedef struct PointNode{
  Point A;
  struct PointNode *next;
}PointNode;

typedef struct LinkedList{
  PointNode *head;
}PointList;

typedef struct Plane{
  float a, b, c, d;
}Plane;

//============================= MATHING =================================
float po_abs(float a){
  if(a < 0) return -a;
  return a;
}

float po_sqrt(float a){
  if(a < 0) return -1;
  
  float result = a;
  while(result - a/result > EPSILON){
    result = (result + a/result)/2;
  }
  
  return result;
}

float dist(Plane P, Point A){
  return po_abs(P.a*A.x + P.b*A.y + P.c*A.z + P.d) / po_sqrt(P.a*P.a + P.b*P.b + P.c*P.c);
}

//============================ LISTING ==================================

PointNode* createNode(Point newPoint){
  PointNode* newPointNode = (PointNode*)malloc(sizeof(PointNode));
  newPointNode->A = newPoint;
  newPointNode->next = NULL;
  return newPointNode;
}

void freeList(PointList *list){
  if(list->head == NULL) return;
  
  PointNode *current = list->head;
  while(current != NULL){
    PointNode *temp = current->next;
    free(current);
    current = temp;
  }
  
  list->head = NULL;
}

void insertDistAscen(PointList *list, Point newPoint, Plane P){
  PointNode *newPointNode = createNode(newPoint);
  if(list->head == NULL){
    list->head = newPointNode;
    return;
  }
  
  if(dist(P, newPoint) < dist(P, list->head->A)){
    newPointNode->next = list->head;
    list->head = newPointNode;
    return;
  }
  
  PointNode *current = list->head;
  while(current->next != NULL && dist(P, newPoint) < dist(P, current->next->A)){
    current = current->next;
  }
  
  newPointNode->next = current->next;
  current->next = newPointNode;
}

void printList(PointList* list){
  if(list->head == NULL){
    printf("List is empty!\n");
    return;
  }
  
  printf("List: ");
  PointNode* current = list->head;
  while(current != NULL){
    printf("(%.2f; %.2f; %.2f) -> ", current->A.x, current->A.y, current->A.z);
    current = current->next;
  }
  printf("NULL\n");
}


int main(){
  Plane P;
  PointList list;
  list.head = NULL;
  Point newPoint;
  scanf("%f%f%f%f", &P.a, &P.b, &P.c, &P.d);
  int i = 0;
  while(1){
    scanf("%f %f %f", &newPoint.x, &newPoint.y, &newPoint.z);
    if(newPoint.x == 0 && newPoint.y == 0 && newPoint.z == 0){
     insertDistAscen(&list, newPoint, P);
     break;
    }
    insertDistAscen(&list, newPoint, P);
  }
  
  printList(&list);
  freeList(&list);
  
  return 0;
}

/*
1 2 -2 1
1 1 1 
2 3 -4
3 3 2
0 0 0

List: (0.00; 0.00; 0.00) -> (1.00; 1.00; 1.00) -> (2.00; 3.00; -4.00) -> (3.00; 3.00; 2.00) -> NULL
*/
