bool isAlphanumeric(char a){
    if(a <= 'Z' && a >= 'A' || a <= 'z' && a >= 'a' || a <= '9' && a >= '0'){
        return true;
    }
    return false;
}

int lowerCase(char a){
    if(a <= 'Z' && a >= 'A'){
        return a + 32;
    }
    return a;
}

bool isPalindrome(char* s) {
    if(strlen(s) == 0) return true;

    int left = 0;
    int right = strlen(s) - 1;

    while(left < right){
        if( !isAlphanumeric(s[left]) ){
            left++;
            continue;
        }
        else if( !isAlphanumeric(s[right]) ){
            right--;
            continue;
        }

        if(lowerCase(s[left]) != lowerCase(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
