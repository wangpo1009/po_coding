#include <stdio.h>

#define MAX 100

void inputArr(char arr[MAX][MAX],int n, int m){
    for(int i = 0; i < n; i++){
        fgets(arr[i],MAX,stdin);
        if(arr[i][m-1] == '\n'){
            arr[i][m-1] = '\0';
        }
    }
}

//String's length is the same in the arr 
int str_cmp(char arrA[], char arrB[]){
    for(int i = 0; arrA[i] != '\0'; i++){
        if(arrA[i] != arrB[i]){
            return -1;
        }
    }
    return 1;
}

int searchString(char arr[MAX][MAX], int n, int m, char str[]){
    int index = -1;
    for(int i = 0; i < n; i++){
         if(str_cmp(arr[i],str) == 1){
            index = i;
            return index;
         }
    }
    return index;
}

int main(){
    char arr[MAX][MAX];
    int arrLen, charLen;
    scanf("%d",&arrLen);
    scanf("%d",&charLen);
    getchar();
    inputArr(arr,arrLen,charLen);
    char str[MAX];
    fgets(str,MAX,stdin);
    if(str[charLen-1] == '\n'){
        str[charLen-1] = '\0';
    }
    int index = searchString(arr, arrLen, charLen, str);
    if(index != -1){
        printf("Tìm thay %s tai %d", str, index);
    }
    else{
        printf("Khong tim thay");
    }
    
}

/*
4
8
01sd203a
98lam780
n1h2u3ng
hvthaott
hvthaott
Tìm thay hvthaott
 tai 3
 */
