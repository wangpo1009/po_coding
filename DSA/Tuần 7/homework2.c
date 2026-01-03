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

//binary search base on recursion
int binaryRecursion(int a[], int left, int right, int val) {
  
  if(left > right){
    return -1;
  }
  
  int mid = (left + right)/2;
  
  if (a[mid] == val){
    return mid; 
  }
  else if(a[mid] < val){
    return binaryRecursion(a, mid+1, right, val);
  }
  else{
    return binaryRecursion(a, left, mid-1, val);
  }
  
}


  
  
int main(){
    int arr1[] = {1, 0, 0, 9, 0, 6};

    printf("========== PART 1: PRINT ARRAY ==========\n");
    printArrUsingRecursion(arr1, 6);

    printf("\n========== PART 2: FIND ELEMENT ==========\n");
    int el = findElementWithRecursion(arr1, 5, 0);
    printf("Target value: 0\n");
    printf("Found at index: %d\n", el);

    printf("\n========== PART 3.1: STACK (POP RECURSION) ==========\n");
    stack s;
    initStack(&s);
    for(int i = 0; i < 20; i++) push(&s, i);
    popWithRecursion(&s, 20);

    printf("\n========== PART 3.2: QUEUE (GET RECURSION) ==========\n");
    queue q;
    initQueue(&q);
    for(int i = 0; i < 20; i++) put(&q, i);
    getWithRecursion(&q, 20);

    printf("\n========== PART 4: BINARY SEARCH ==========\n");
    int arr2[10] = {1,2,3,4,5,6,7,8};
    int pos = binaryRecursion(arr2, 0, 7, 7);
    printf("Target value: 7\n");
    printf("Found at index: %d\n", pos);

    return 0;
}
/*
Input for the program ( Optional )
STDIN
Output:

========== PART 1: PRINT ARRAY ==========
a[0] = 1
a[1] = 0
a[2] = 0
a[3] = 9
a[4] = 0
a[5] = 6

========== PART 2: FIND ELEMENT ==========
Target value: 0
Found at index: 4

========== PART 3.1: STACK (POP RECURSION) ==========
pop 20: 19
pop 19: 18
pop 18: 17
pop 17: 16
pop 16: 15
pop 15: 14
pop 14: 13
pop 13: 12
pop 12: 11
pop 11: 10
pop 10: 9
pop 9: 8
pop 8: 7
pop 7: 6
pop 6: 5
pop 5: 4
pop 4: 3
pop 3: 2
pop 2: 1
pop 1: 0

========== PART 3.2: QUEUE (GET RECURSION) ==========
0 value: 19
1 value: 18
2 value: 17
3 value: 16
4 value: 15
5 value: 14
6 value: 13
7 value: 12
8 value: 11
9 value: 10
10 value: 9
11 value: 8
12 value: 7
13 value: 6
14 value: 5
15 value: 4
16 value: 3
17 value: 2
18 value: 1
19 value: 0

========== PART 4: BINARY SEARCH ==========
Target value: 7
Found at index: 6
*/
