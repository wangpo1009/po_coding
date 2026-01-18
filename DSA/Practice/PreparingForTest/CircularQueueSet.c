#include <stdio.h>

#define MAX 10

typedef struct{
  int data[MAX];
  int head, tail;
}queue;

void init(queue *q){
  q -> head = -1;
  q -> tail = -1;
}

int isEmpty(queue *q){
  if(q -> head == -1){
    return 1;
  }
  return 0;
}

int isFull(queue *q){
  if(q -> head == MAX - 1 && q -> tail == 0 ||
     q -> tail == (q -> head - 1)){
       return 1;
  }
  return 0;
}

void put(queue *q, int val){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }

    if(isEmpty(q)){
        q->head = q->tail = 0;
    }
    else{
        q->tail = (q->tail + 1) % MAX;
    }

    q->data[q->tail] = val;
}

int get(queue *q){
  if( !isEmpty(q) ){
    int val = q -> data[q -> head++];
    
    if(q->head == q->tail){
      q->head = q->tail = -1;
    }
    else{
      q->head = (q->head + 1) % MAX;
    }
    
    return val;
  }
  
  return;
}


void displayQueue( queue q ){
  if( isEmpty(&q) ){
    return;
  }
  
  int j = 0;
  int i = q.head;
  
  while(1){
    printf("STT %d: %d", j++, q.data[i]);
    if(i == q.tail){
      break;
    }
    i = (i + 1) % MAX;
  }
}

