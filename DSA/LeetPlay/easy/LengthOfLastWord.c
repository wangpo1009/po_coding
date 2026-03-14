int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;
    while( i >= 0 && s[i] == ' ' ){
        i--;
        continue;
    }    
    while( i >= 0 && s[i] != ' ' ){
        length++;
        i--;
    }
    return length;
}
