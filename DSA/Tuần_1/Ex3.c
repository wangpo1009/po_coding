#include <stdio.h>

#define MAX 100
void inputArr(char arr[MAX][MAX],int n, int m){
    for(int i = 0; i <= n; i++){
        fgets(arr[i],MAX,stdin);
        if(arr[i][m-1] == '\n'){
            arr[i][m-1] = '\0';
        }
    }
}

void printArr(char arr[MAX][MAX], int n, int m){
    for(int i = 0; i <= n; i++){
        printf("%s",arr[i]);
    }
}
int str_cmp(char arrA[], char arrB[]){
    for(int i = 0; arrA[i] != '\0'; i++){
        if(arrA[i] != arrB[i]){
            return -1;//ko giong
        }
    }
    return 1;//giong
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
    printf("Nhap do dai cua mang:\n");
    scanf("%d",&arrLen);
    printf("Nhap do dai cua chuoi trong mang:\n");
    scanf("%d",&charLen);
    inputArr(arr,arrLen,charLen);
    printArr(arr,arrLen,charLen);
    char str[MAX];
    printf("Nhap chuoi muon tim kiem:");
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
