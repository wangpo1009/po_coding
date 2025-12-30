#include <stdio.h>

#define MAX 100

typedef struct stack{
    int data[MAX];
    int top;
}stack;

typedef struct queue{
    int data[MAX];
    int head, tail;
}queue;

//Some function to process stack
void initStack(stack *s){
    s -> top = -1;
}

int isStackFull(stack s){
    if(s.top == MAX-1){
        return 1;
    }
    return 0;
}

int isStackEmpty(stack s){
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int pop(stack *s){
  if(!isStackEmpty(*s)){
    return s->data[(s->top)--];
  }
  return -1;
}

void push(stack *s, int val){
  if(!isStackFull(*s)){
    s->data[++(s->top)] = val;
  }
  return;
}

//some function to process queue
void initQueue(queue *q){
  q->head = 0;
  q->tail = -1;
}

int isQueueFull(queue q){
  if(q.tail == MAX-1){
    return 1;
  }
  return 0;
}

int isQueueEmpty(queue q){
  if(q.tail == -1){
    return 1;
  }
  return 0;
}

int get(queue *q){
    if(!isQueueEmpty(*q)){
      return q->data[(q->head)++];
    }
    return -1;
}

void put(queue *q, int val){
  if(!isQueueFull(*q)){
    q->data[++(q->tail)] = val;
  }
  return ;
}

//Print array from i = 0 -> i = n-1 with recursion
void printArrUsingRecursion(int arr[], int i){
  if(i == 0){
    return;
  }
  printArrUsingRecursion(arr, i - 1);
  printf("a[%d] = %d\n", i - 1, arr[i-1]);
}

//Find an elements in the array by scanning the array from i = n until meet the value else return -1;
int findElementWithRecursion(int arr[], int n, int value){
  if(arr[n] == value){
    return n;
  }
  
  if( n < 0){
    return -1;
  }
  
  findElementWithRecursion(arr, --n, value);
}

//pop stack with recursion
void popWithRecursion(stack *s, int n){
    if(n == 0){
        return;
    }
    int val = pop(s);
    printf("pop %d: %d\n", n, val);
    popWithRecursion(s,--n);
}

//get queue with recursion
void getWithRecursion(queue *q, int n){
    if(n == 0) return ;
    int val = get(q);
    getWithRecursion(q,--n);
    printf("%d value: %d\n",n, val);
}


int main(){
  int arr[] = {1, 0, 0, 9, 0, 6};
  //1.
  printf("Printing arr using recursion:\n");
  printArrUsingRecursion(arr, 6);
  printf("================\n");
  
  //2.
  int el = findElementWithRecursion(arr, 6, 0);
  printf("Found 0 at %d\n", el);
  printf("================\n");
  
  //3.1
  int n = 20;
  stack s;
  initStack(&s);
  for(int i = 0; i < n; i++){
      push(&s, i);
  }
  popWithRecursion(&s,n);
  printf("================\n");
  
  //3.2
  queue q;
  initQueue(&q);
  for(int i = 0; i < n; i++){
      put(&q,i);
  }
  getWithRecursion(&q,n);
  printf("================\n");
  
  
  
  return 0;
}
