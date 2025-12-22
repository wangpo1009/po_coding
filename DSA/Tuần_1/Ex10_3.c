#include <stdio.h>

#define MAX 255

int strLen(char str[]){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

void poisonDelete(char str[], char poison[]){
    int poisonLen = strLen(poison);
    int i = 0;
    while(str[i] != '\0'){
        int j = 0;
        while(j < poisonLen && str[i + j] == poison[j]){
            j++;
        }
        if(j == poisonLen){
            int k = i;
            while(str[k + poisonLen] != '\0'){
                str[k] = str[k + poisonLen];
                k++;
            }
            str[k] = '\0';
        } else {
            i++;
        }
    }
}

void poisonAttack(char str[], char poisons[MAX][MAX], int poisonCount){
    for(int i = 0; i < poisonCount; i++){
        poisonDelete(str, poisons[i]);
    }
}


void poisonCleanup(char str[], char poison[]) {
    int poisonLen = strLen(poison);
    int i = 0;

    while (str[i] != '\0') {
        int j = 0;
        while (j < poisonLen && str[i + j] == poison[j]) {
            j++;
        }

        if (j == poisonLen) { // Found a match
            int currentLen = strLen(str);
            
            
            for (int k = currentLen; k >= i + poisonLen; k--) {
                str[k + poisonLen] = str[k];
            }

            /*
            deform the poison string
            create a temporary array where
            the even index characters are the same as the poison string
            the odd index characters are incremented by 1
            */
            char temp[poisonLen * 2];
            for (int m = 0; m < poisonLen; m++) {
                temp[m * 2] = poison[m];           
                temp[m * 2 + 1] = poison[m] + 1;   
            }

            // Copy the temp array back to the original string
            for (int m = 0; m < poisonLen * 2; m++) {
                str[i + m] = temp[m];
            }

            // Move index forward to avoid re-checking the newly inserted characters
            i += (poisonLen * 2);
        } else {
            i++;
        }
    }
}

void strCleanup(char str[], char poisons[MAX][MAX], int poisonCount) {
    for (int i = 0; i < poisonCount; i++) {
        poisonCleanup(str, poisons[i]);
    }
}

int main(){
    char str[MAX];
    fgets(str, MAX, stdin);


    int poisonCount;
    char poisons[MAX][MAX];
    printf("Enter number of poison strings: ");
    scanf("%d", &poisonCount);
    getchar(); 

    for(int i = 0; i < poisonCount; i++){
        printf("Enter poison string %d: ", i + 1);
        fgets(poisons[i], MAX, stdin);
        int len = strLen(poisons[i]);
        if(len > 0 && poisons[i][len - 1] == '\n'){
            poisons[i][len - 1] = '\0';
        }
    }
    
    // poisonAttack(str, poisons, poisonCount);
    // printf("String after poison attack: %s\n", str);


    strCleanup(str, poisons, poisonCount);
    printf("String after cleanup: %s\n", str);
    return 0;
}
/*
Phongdihocdsa100906
Enter number of poison strings: 2
Enter poison string 1: di
Enter poison string 2: dsa
String after poison attack: Phonghoc100906
*/
/*
Phongdihocdsa100906
Enter number of poison strings: 2
Enter poison string 1: di
Enter poison string 2: 0906
String after cleanup: Phongdeijhocdsa10019:0167
*/
