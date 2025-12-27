#include <stdio.h>

#define MAX 100

typedef struct stack{
    int data[MAX];
    int top;
}stack;

typedef struct queue{
  int data[MAX];
  int head, tail;
}

//Some function to preprocessing stack
void initStack(stack *s){
    s -> top = -1;
}

int isFull(stack s){
    if(s.top == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(stack s){
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int pop(stack *s){
  if(!isEmpty(*s)) return s -> data[(s->top)--]; 
  return -1;
}

int top(stack *s){
  if(!isEmpty(*s)){
    return s->data[(s->top)];
  }
  else{
    return -1;
  }
}

void push(stack *s, int val){
  if(!isFull(*s)){
    s->data[++(s->top)] = val;
  }
  return;
}

//Some function to preprocessing queue
void initQueue(queue *q){
  q->head = 0;
  q->tail = -1;
}

int isEmpty(queue q){
  if(q.tail == -1){
    return 1;
  }
  return 0;
}

int isFull(queue q){
  if(q.head == MAX-1){
    return 1;
  }
  return 0;
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

//popping stack with recursion
int  popWithRecursion(stack *s, int n){
  //base case
  if(isEmpty(*s)){
    return;
  }
  printf("%d \n", pop(s));
  popWithRecursion(s, --n);
}

//
int main(){
  int arr[] = {1, 0, 0, 9, 0, 6};
  printf("Printing arr using recursion:\n");
  printArrUsingRecursion(arr, 6);
  printf("================\n");
  
  int el = findElementWithRecursion(arr, 6, 0);
  printf("Found 0 at %d\n", el);
  printf("================\n");
  
  stack s;
  initStack(&s);
  int n = 20;
  for(int i = 0; i < 20; i ++){
    push(&s,i);
  }
  printf("Popping array with recursion:\n");
  popWithRecursion(&s, 19);
  printf("================\n");
  
  
  
  
  return 0;
}
