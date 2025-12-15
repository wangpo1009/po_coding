#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Stack{
    int a[MAX];
    int topInd;
}stack;

// initialize new stack.
void init(stack *s){
    s -> topInd = -1;//Điều này giống (*s).top = -1;
}

// checking if stack is empty or not
int isEmpty(stack *s){
    if(s -> topInd == -1){
        return 1;
    }
    return 0;
}

int isFull(stack *s){
    if(s -> topInd == MAX - 1){
        return 1;
    }
    return 0;
}

void push(stack *s, int val){
    s -> topInd++;
    (*s).a[s -> topInd] = val;
}

int pop(stack *s){
    int val = s->a[s->topInd];
    s->topInd--;
    return val;
}

void displayStack(stack *s){
    for(int i = 0; i <= s -> topInd; i++){
        printf("%d ", (*s).a[i]);
    }
}

void main(){
    stack s;
    init(&s);
    int num[6] = {1, -2, 3, -4, 5, -6};
    //push
    printf("< MAX = %d >\n", MAX);
    printf("======== PUSH ========\n");
    for(int i = 0; i < 6; i++){
        printf("Push %d: \n", num[i]);
        if(!isFull(&s)){
            push(&s,num[i]);
            displayStack(&s);
            printf("\n");
        }
        else{
            printf("Stack is full!\n");
        }
    }
    printf("\n");
    //pop
    printf("======== POP ========\n");
    int i = 0;
    while(!isEmpty(&s)){
        printf("Pop %d: %d\n",i, pop(&s));
        displayStack(&s);
        i++;
        printf("\n");
    }
}
