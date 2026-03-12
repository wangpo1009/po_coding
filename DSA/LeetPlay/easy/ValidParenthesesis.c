bool isOpen(char s){
    if(s == '(' || s == '[' || s == '{') return true;
    return false;
}

bool isClose(char s){
    if(s == ')' || s == ']' || s == '}') return true;
    return false;
}


bool isValid(char* s) {
    char* stack = (char*)malloc(sizeof(char) * (strlen(s) +1));
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++){
        if(isOpen(s[i])){
            stack[++top] = s[i];
        }
        if(isClose(s[i])){
            if(top == -1) return false;
            char open = stack[top--];
            if(s[i] == ')' && open != '(') return false;
            if(s[i] == ']' && open != '[') return false;
            if(s[i] == '}' && open != '{') return false;
        }
    }
    return (top == -1);
}
