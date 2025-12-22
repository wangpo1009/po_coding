#include <stdio.h>

#define MAX 100;

typedef struct arrOfThreeFloats{
    float a, b, c;
}arrOfThreeFloats;

void bubbleSort(float arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortChar(char arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

float functionF(arrOfThreeFloats arr){
    return arr.a - 2*arr.b + 3*arr.c;
}

void bubbleSortArrOfThreeFloats(arrOfThreeFloats arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(functionF(arr[j]) > functionF(arr[j+1])){
                arrOfThreeFloats temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main(){
    //Sorting float array using bubble sort
    float arr[] = {64.5, 34.2, 25.1, 12.6, 22.9, 11.0, 90.3, 10.09, 5.5, 75.8};
    int n = 10;
    bubbleSort(arr, n);
    printf("Sorted float array: \n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    /*
    Sorted array: 
    5.50 10.09 11.00 12.60 22.90 25.10 34.20 64.50 75.80 90.30 
    */

    //Sorting alphabet char array using bubble sort
    char charArr[] = {'d', 'a', 'c', 'b', 'E', 'D', 'B', 'A', 'e', 'C'};
    int m = 10;
    bubbleSortChar(charArr, m);
    printf("Sorted char array: \n");
    for(int i = 0; i < m; i++){
        printf("%c ", charArr[i]);
    }
    printf("\n");
    /*
    Sorted char array:
    A B C D E a b c d e
    */

    //Sorting array of three floats based on functionF
    arrOfThreeFloats arrThree[] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {0.5, 1.5, 2.5},
        {3.0, 2.0, 1.0},
        {2.0, 3.0, 4.0},
        {5.0, 4.0, 3.0},
        {1.5, 2.5, 3.5},
        {6.0, 5.0, 4.0},
        {2.5, 1.5, 0.5},
        {3.5, 4.5, 5.5}
    };
    int p = 10;
    bubbleSortArrOfThreeFloats(arrThree, p);
    printf("Sorted array of three floats based on functionF: \n");
    for(int i = 0; i < p; i++){
        printf("(%.1f, %.1f, %.1f) -> f=%.2f\n", arrThree[i].a, arrThree[i].b, arrThree[i].c, functionF(arrThree[i]));
    }
    /*
    Sorted array of three floats based on functionF:
    (2.5, 1.5, 0.5) -> f=1.00
    (3.0, 2.0, 1.0) -> f=2.00
    (0.5, 1.5, 2.5) -> f=5.00
    (1.0, 2.0, 3.0) -> f=6.00
    (5.0, 4.0, 3.0) -> f=6.00
    (1.5, 2.5, 3.5) -> f=7.00
    (2.0, 3.0, 4.0) -> f=8.00
    (6.0, 5.0, 4.0) -> f=8.00
    (3.5, 4.5, 5.5) -> f=11.00
    (4.0, 5.0, 6.0) -> f=12.00
    */
    return 0;
}
