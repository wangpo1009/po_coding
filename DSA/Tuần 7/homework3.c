#include <stdio.h>

#define MAX 20

typedef struct stack{
  int data[MAX];
  int top;
}stack;

void initStack(stack* s){
  s->top = -1;
}

void push(stack* s, int val){
  if(s->top == MAX-1){
    printf("Stack is full\n");
    return ;
  }

  s->data[++(s->top)] = val;
}

int pop(stack* s){
  if(s->top == -1){
    printf("Stack is empty\n");
    return -1;
  }
  
  return s->data[(s->top)--];
}

void pushUntil_1(stack* s, int arr[], int n){
    if(n < 0){
        return; // there's no 1
    }

    if(arr[n] == 1){
        push(s, 1);
        return;
    }

    pushUntil_1(s, arr, n - 1);
    push(s, arr[n]);
}

/*
base case: when n== 0 or arr[n]==1
base case returns:
    if arr[n]==1: push arr[n] and return
    if n==0: return
before base case:
    (1)call pushUntil_1 with n-1
        ->base case
    (2)push arr[n]
before before:
    (1)call pushUntil_1 with n-1
        ->call pushUntil_1 with n-2
        ->push arr[n-2]
    (2)push arr[n-1]
    (3)push arr[n]


*/


void popAndSumUntil_1(stack* s, int* sum){
    if(s->top == -1){
        return ;
    }
    int val = pop(s);

    if(val == 1){
        (*sum) += 1;
        return;
    }

    (*sum) += val;
    popAndSumUntil_1(s, sum);
}

void printStack(stack* s){
    
    for(int i = s->top; i != -1; i--){
      printf("%d > ", s->data[i]);
    }  
}

int main(){
    int arr[MAX] = {2, 4, 2, 5, 6, 7, 9, 3, 2, 5, 6, 1, 7, 4, 3, 4, 8, 9, 7, 10};
    stack s;
    initStack(&s);
  
    pushUntil_1(&s, arr, MAX-1);
    printStack(&s);

    int sum = 0;
    popAndSumUntil_1(&s, &sum);
    printf("\nSum until 1: %d\n", sum);
    return 0;
}

