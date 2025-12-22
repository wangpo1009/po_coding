#include <stdio.h>

#define MAX 100

void deleteSimilaritiesWithLinearSearch(int arr[], int *n, int *linearSteps){
    for(int i = 0; i < *n; i++){
        for(int j = i + 1; j < *n; ){
            (*linearSteps)++;
            if(arr[j] == arr[i]){
                for(int k = j; k < *n - 1; k++){
                    arr[k] = arr[k + 1];
                    (*linearSteps)++;
                }
                (*n)--;   
            } else {
                j++;  
            }
        }
    }
}

void bubbleSort(int arr[], int n, int *steps){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            (*steps)++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void deleteSimilaritiesWithBubbleSort(int arr[], int *n, int *steps){
    bubbleSort(arr, *n, steps);

    if(*n == 0) return;

    int write = 1; 

    for(int read = 1; read < *n; read++){
        (*steps)++; 
        if(arr[read] != arr[read - 1]){
            arr[write++] = arr[read];
            (*steps)++;
        }
    }

    *n = write;
}

int main(){
    int arr1[] = {1, 2, 4, 2, 5, 1, 3, 4, 2, 1};
    int n = 10;
    int linearSteps = 0;
    deleteSimilaritiesWithLinearSearch(arr1, &n, &linearSteps);
    printf("Array after deleting similarities: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nNumber of linear search steps: %d\n", linearSteps);
    printf("\n");

    int arr2[] = {1, 2, 4, 2, 5, 1, 3, 4, 2, 1};
    n = 10;
    int bubbleSteps = 0;
    deleteSimilaritiesWithBubbleSort(arr2, &n, &bubbleSteps);
    printf("Array after deleting similarities using bubble sort: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr2[i]);
    }
    printf("\nNumber of bubble sort steps: %d\n", bubbleSteps);
    return 0;
}

/*
Array after deleting similarities: 
1 2 4 5 3 
Number of linear search steps: 27

Array after deleting similarities using bubble sort:
1 2 3 4 5
Number of bubble sort steps: 58

In conclusion, the linear search method required fewer steps (27) compared to the bubble sort method (58) for this specific array
Cause the linear search method have the complexity of O(n^2) in the worst case, while the bubble sort method has a complexity of O(n^2) for sorting plus O(n) for removing duplicates, leading to a higher total step count. 
*/
