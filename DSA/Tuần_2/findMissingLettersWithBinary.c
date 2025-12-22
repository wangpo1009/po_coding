#include <stdio.h>

#define MAX 30

int findingNemo(char alphabet[], int len){
    int left =0;
    int right = len-1;
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(alphabet[mid] - 'a' == mid){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return 'a' + left;
}

void insertMissingLetter(char alphabet[], char missing_letter, int *len){
    (*len)++;
    int i = *len - 1;
    while (i > (int) (missing_letter - 'a'))
    {
        alphabet[i] = alphabet[i - 1];
        i--;
    }
    alphabet[i] = missing_letter;
}

int main(){
    char alphabet[] = "abdefghijklmnopqrstuvwxyz";
    int alphabet_len = 25;
    int nemo = findingNemo(alphabet, alphabet_len);
    printf("The missing letter is: %c\n", nemo);
    insertMissingLetter(alphabet, nemo, &alphabet_len);
    printf("The complete alphabet is: ");
    for(int i =0; i < alphabet_len; i++){
        printf("%c ", alphabet[i]);
    }

}
/*
The missing letter is: c
The complete alphabet is: a b c d e f g h i j k l m n o p q r s t u v w x y z
*/
