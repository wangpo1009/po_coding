/*
Bài 2: (Parenthesis) Viết chương trình C cho phép học sinh nhập vào một chuỗi lưu trữ dãy các số, 
phép tính và dấu ngoặc ( ), [ ], { }, chương trình kiểm tra tính hợp lệ của các dấu ngoặc của dãy phép tính. 
Nếu dãy phép tính chưa hợp lệ, hãy chỉ ra vị trí lỗi sai và đề xuất một phương án phép tính hợp lệ.
Biết rằng các dấu ngoặc luôn được nhập vào theo cặp một cách đầy đủ và luôn đứng đúng vị trí.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>// need it for the strlen. im too lazy to make one...
#define MAX 100

typedef struct stack{
  char value[MAX];
  int top;
}stack;

// Bracket processing
int isOpenBracket(char val){
  switch(val){
    case '(': return 1;
    case '[': return 1;
    case '{': return 1;
  }
  return 0; 
}

int isCloseBracket(char val){
  switch(val){
    case ')': return 1;
    case ']': return 1;
    case '}': return 1;
  }
  return 0; 
}

char equivalBracket(char openBracket){
  switch(openBracket){
    case '(': return ')';
    case '[': return ']';
    case '{': return '}';
  }
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

// Stacking premise
void init(stack *s){
  s->top = -1;
}

int isEmpty(stack s){
  if(s.top == -1){
    return 1;//isEmpty
  }
  return 0;//instEmpty
}

void push(stack *s, char val){
  if(s->top == MAX-1){
    printf("Stack is full!");
    return ;
  }
  s->value[++(s->top)] = val;
}

char pop(stack *s){
  if(isEmpty(*s)){
    printf("Stack is empty!");
    return 0;
  }
  return s->value[(s->top)--];
}

//solving problem with stacking
int checkForErrorWithStack(char operation[], int errInd[]) {
  stack bracket;
  init(&bracket);
  
  int j = 0;
  int i = 0;
  while(operation[i] != '\0'){
    if(isOpenBracket(operation[i])){
      push(&bracket, operation[i]);
    }
    
    char curBracket;
    if(isCloseBracket(operation[i])){
      curBracket = pop(&bracket);
      if(!isMatching(curBracket, operation[i])){
        errInd[j++] = i;
        operation[i] = equivalBracket(curBracket);
      }
    }
    i++;
  }
  if(j == 0){
    return 0;
  }
  return 1;
}

// solving problem with arr malnipulation 
int CheckingErrorWithArr(char operation[], int errInd[]){
  int left = 0;
  int right = strlen(operation)-1;
  int i = 0;
  
  while(left < right){
    
    while ( !isOpenBracket(operation[left]) ) {
      left++;
    }

    while ( !isCloseBracket(operation[right]) ) {
      right--;
    }
    
    if( !isMatching(operation[left], operation[right])){
      errInd[i++] = right;
      operation[right] = equivalBracket( operation[left] );
      left++;
      right--;
    }
    else{
      left++;
      right--;
    }
    
    if (left >= right) {
      break; 
    }
    
  }
  
  if(i == 0) return 0;
  return 1;
}

// the arr method cannot check for multiple same levels bracket


int main()
{
  char operation[] = "{-1+2*[3+5*(1-3]:2}-2)";
  int errInd[MAX] = {};
  //Stacking method test
  if(checkForErrorWithStack(operation, errInd)){
    printf("Error at: ");
    for(int i = 0; errInd[i] != 0; i++){
      printf("%d ", errInd[i]);
    }
    printf("\n");
    printf("Corrected operation: %s", operation);
  }
  else{
    printf("No error!\n");
  }
  
  printf("\n");
  //Array method test
  int errIndA[MAX] = {};
  char operationA[] = "{-1+2*[3+5*(1-3]:2}-2)";
  if(CheckingErrorWithArr(operationA, errIndA)){
    printf("Error at: ");
    for(int i = 0; errIndA[i] != 0; i++){
      printf("%d ", errIndA[i]);
    }
    printf("\n");
    printf("Corrected operation: %s", operationA);
  }
  else{
    printf("No error!");
  }
  
  return 0;
}
