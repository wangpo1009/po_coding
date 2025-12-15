/*
Bài 1: (Reverse) Cài đặt chương trình C cho phép nhập vào một xâu ký tự có độ dài không quá 1000, 
hãy đảo ngược chuỗi ký tự đó bằng hai cách:
- Cách 1: Dùng kỹ thuật xử lý mảng thông thường.
- Cách 2: Dùng cấu trúc dữ liệu Stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct stack{
  char a[MAX];
  int top;
}stack;

//Reverse using normal algorithm for array
void reverseStr(char str[], int strLen){
  int left = 0;
  int right = strLen-1;
  while(left < right){
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

// Reverse using stack structure
void initStack(stack *s){
  s->top = -1;
}
int isEmpty(stack *s){
  if(s->top == -1){
    return 1;
  }
  return 0;
}

int isFull(stack *s){
  if(s->top == MAX -1){
    return 1;
  }
  return 0;
}

char pop(stack *s){
  if(isEmpty(s)){
    printf("Toi nho em!"); 
    return 0; 
  }
  char val = s->a[s->top];
  s->top--;
  return val;
} 

void push(stack *s, char val){
  if(isFull(s)){
    printf("Toi that su rat nho em, em co hay?");
  }
  s->top++;
  s->a[s->top] = val;
}

void reverseStringWithStack(char str[]) {
    stack s;
    initStack(&s);
    
    // 1. Push: Iterate through the string and push every character onto the stack
    int i = 0;
    while (str[i] != '\0' && !isFull(&s)) {
        push(&s, str[i]);
        i++;
    }
    
    // 2. Pop: Reset the index and pop characters back into the string
    i = 0;
    while (!isEmpty(&s)) {
        str[i] = pop(&s);
        i++;
    }
}

int main(){
  char str[] = "phong";
  reverseStr(str,5);
  printf("Reverse 1st time: %s\n", str);
  reverseStringWithStack(str);
  printf("Reverse 2nd time: %s\n", str);
  
  return 0;
}
