
/*
Bài 3: (Reverse Polish Notation/Postfix) 
Viết chương trình C cho phép người dùng nhập vào một chuỗi ký tự là một dãy phép tính chỉ bao gồm các số có 1 chữ số và phép toán +, -, *, / (không bao gồm dấu ngoặc). Hãy lưu trữ biểu thức đó dưới dạng hậu tố rồi tính kết quả của biểu thức.
Gợi ý: Sử dụng stack để lưu trữ số và phép tính theo thứ tự ưu tiên của phép tính.

*/
#include <stdio.h>

#define MAX 100

typedef struct stack{
  int data[MAX];
  int top;
}stack;

void init(stack *s){
  s->top = -1;
}

int isEmpty(stack s){
  if(s.top == -1){
    return 1;
  }
  return 0;
}

int isFull(stack s){
  if(s.top == MAX -1){
    return 1;
  }
  return 0;
}

void push(stack *s, int val){
  if(!isFull(*s)){
    s->data[++(s->top)] = val;
  }
}

int pop(stack *s){
  if(!isEmpty(*s)){
    return s->data[s->top--];
  }
  return 0;
}

int getPriority(char op){
  if(op == '+' || op == '-'){
    return 1;
  }
  if(op == '*' || op == '/'){
    return 2;
  }
  return 0;
}

int isNumber(char val){
  if(val >= '0' && val <= '9'){
    return 1;
  }
  return 0;
}

int top(stack s){
  if(!isEmpty(s)){
    return s.data[s.top];
  }
  return 0;
}

//transforming infix to postfix
void postfixTrans(char str[], char postfix[]){
  int j = 0;
  stack op;
  init(&op);
  
  for(int i = 0; str[i] != '\0'; i++){
    if(isNumber(str[i])){
      postfix[j++] = str[i];
    }
    else{
      while(!isEmpty(op)){
        if(getPriority(top(op)) >= getPriority(str[i])){
          postfix[j++] = pop(&op);
        }
        else{
          break;
        }
      }
      push(&op, str[i]);
    }
  }
  while(!isEmpty(op)){
    postfix[j++] = pop(&op);
  }
  postfix[j] = '\0';
}

//calulate the result base on the postfix string
int calPostfix(char postfix[]){
  int res;
  stack nums;
  init(&nums);
  
  for(int i = 0; postfix[i] != '\0'; i++){
    if(isNumber( postfix[i] )){
      push(&nums, postfix[i] - '0');
    }
    else{
      int b = pop(&nums);
      int a = pop(&nums);
      switch(postfix[i]){
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
      }
      push(&nums, res);
    }
  }
  return res;
}

int main()
{
  char infix[] = {"1*2+3*4-5*6/5*3/9+6/3*5"};
  char postfix[MAX];
  postfixTrans(infix, postfix);
  printf("%s\n", postfix);
  printf("%d", calPostfix(postfix));
  
  return 0;
}
