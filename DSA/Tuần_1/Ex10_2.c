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
    
    poisonAttack(str, poisons, poisonCount);
    printf("String after poison attack: %s\n", str);
    return 0;
}
