#include <stdio.h>

#define MAX 100
void insertionSort(int arr[], int n, int *steps){
  (*steps) = 0;
  for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0){
      (*steps)++;
      if(arr[j] > key){
        (*steps)++;
        arr[j+1] = arr[j];
        j--;
      }
      else{
        break;
      }
    }
    arr[j + 1] = key;
    (*steps)++;
  }
}

void selectionSort(int arr[], int n, int *steps){
  (*steps) = 0;
  for(int i = 0; i < n; i++){
    int minInd = i;
    for(int j = i + 1; j < n; j++){
      (*steps)++;
      if(arr[j] < arr[minInd]){
        minInd = j;
      }
    }
    if(minInd != i){
      (*steps)++;
      int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
  }    
}

void bubbleSort(int arr[], int n, int *steps){
  (*steps) = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      (*steps)++;
      if(arr[j] > arr[j+1]){
        (*steps)++;
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main()
{
  int insertionInd, selectionInd, bubbleInd;
  int n = 10;
  int arr1[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
  insertionSort(arr1, n, &insertionInd);
  printf("Array after insertion sort: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr1[i]);
  }
  printf("\nSteps count = %d", insertionInd);
  
  printf("\n");
  
  int arr2[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
  selectionSort(arr2, n, &selectionInd);
  printf("Array after selection sort: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr2[i]);
  }
  printf("\nSteps count = %d", selectionInd);
  
  printf("\n");
  
  int arr3[] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
  bubbleSort(arr3, n, &bubbleInd);
  printf("Array after bubble sort: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr3[i]);
  }
  printf("\nSteps count = %d", bubbleInd);
  
  return 0;
  
}

/*
Array after insertion sort: 0 1 1 2 3 3 5 6 8 9 
Steps count = 66
Array after selection sort: 0 1 1 2 3 3 5 6 8 9 
Steps count = 51
Array after bubble sort: 0 1 1 2 3 3 5 6 8 9 
Steps count = 70
*/
