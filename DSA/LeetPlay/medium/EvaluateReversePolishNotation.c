typedef struct{
    int* data;
    int top;
}stack;

bool isNum(char* s){
    if((s[0] <= '9' && s[0] >= '0') || (s[0] == '-' && strlen(s) > 1)) return true;
    return false;
}

int evalRPN(char** tokens, int tokensSize) {
    stack nums;
    nums.top = -1;
    nums.data = (int*)malloc(sizeof(int) * (tokensSize/2 + 1));

    for(int i = 0; i < tokensSize; i++){
        if( isNum(tokens[i]) ){
            nums.data[++nums.top] = atoi(tokens[i]);
        }
        else{
            int a = nums.data[nums.top--];
            int b = nums.data[nums.top--];
            if(tokens[i][0] == '+'){
                nums.data[++nums.top] = a + b;
            }
            if(tokens[i][0] == '-'){
                nums.data[++nums.top] = b - a;
            }
            if(tokens[i][0] == '*'){
                nums.data[++nums.top] = a * b;
            }
            if(tokens[i][0] == '/'){
                nums.data[++nums.top] = b/a;
            }
        }
    }
    return nums.data[0];
}
