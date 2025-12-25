#include <stdio.h>

#define MAX 100

typedef struct stack{
    int data[MAX];
    int top;
}stack;

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
        return 1
    }
    return 0;
}

int pop(stack *s){
    
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

//
int main(){
  int arr[] = {1, 0, 0, 9, 0, 6};
  printf("Printing arr using recursion:\n");
  printArrUsingRecursion(arr, 6);
  printf("================\n");
  
  int el = findElementWithRecursion(arr, 6, 0);
  printf("Found 0 at %d\n", el);
  printf("================\n");
  
  
  
  
  return 0;
}
