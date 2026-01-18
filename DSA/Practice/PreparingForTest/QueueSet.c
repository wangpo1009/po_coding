#include <stdio.h>

#define MAX 100

typedef struct queue{
  int data[MAX];
  int head, tail;
}queue;

void initQueue(queue *q){
  q->head = 0;
  q->tail = -1;
}

int isEmpty(queue *q){
  if(q->tail == -1){
    return 1;
  }
  return 0;
}

int isFull(queue *q){
  if(q->head == MAX-1){
    return 1;
  }
  return 0;
}

void push(queue *q, int val){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }

    if(isEmpty(q)){
        q->head = 0;
    }

    q->tail++;
    q->data[q->tail] = val;
}

int get(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->head];

    if(q->head == q->tail){
        q->head = q->tail = -1;
    }
    else{
        q->head++;
    }

    return value;
}

void printQueue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for(int i = q->head; i <= q->tail; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
