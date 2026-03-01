//Version 1:
int compare(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
}

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;

    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);

    return strcmp(s, t) == 0;
}


//Version 2:
bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;

    int a[26] = {};
    int b[26] = {};

    for(int i = 0; s[i] != '\0'; i++){
        a[s[i] - 97]++;
        b[t[i] - 97]++;
    }

    for(int i = 0; i < 26; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

//Version 3:
bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;
    
    int count[26] = {};

    for(int i = 0; s[i] != '\0'; i++){
        count[s[i] - 97]++;
        count[t[i] - 97]--;
    }

    for(int i = 0; i < 26; i++){
        if(count[i] != 0) return false;
    }
    return true;
}
