#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 255


void initializeArr(int arr[], int n){
  for(int i = 0; i < n; i++){
    arr[i] = rand() % MAX;
  }
}

float mean(int arr[], int n, int k){
  float sum = 0;
  for(int i = 0; i < n; i++){
    sum += (float) i* (float)arr[i];
  }
  return sum/(float)k;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

void quickSort(int arr[], int left, int right, int* count){
  if(left < right){
    (*count)++;
    int piv = partition(arr, left, right);
    quickSort(arr, left, piv-1, count);
    quickSort(arr, piv+1, right, count);
  }
  return ;
}

int main(){
  time_t t;
  srand((unsigned)time(&t));
  
  int k[4] = {10, 100, 1000, 10000};
  int n = 10;
  int count = 0;
  int freqTab[10] = {};
  int arr[MAX];
  
  
  for(int i = 0; i < 4; i++){
    
    for(int j = 0; j < 10; j++){
      freqTab[j] = 0;
    } 
    
    for(int j = 0; j < k[i]; j++){
      count = 0;
      initializeArr(arr, n);
      quickSort(arr, 0, n-1, &count);
      freqTab[count]++;
    }
    
    printf("WITH K = %d: \n",k[i]);
    printf("Count: ");
    for(int j = 0; j < 10; j++){
      printf(" %d \n", freqTab[j]);
    }
    float mn = mean(freqTab, 10, k[i]);
    printf("Mean : %.4f\n", mn);
    printf("===========================\n");
  }
  
  
  return 0;
}
/*
WITH K = 10: 
Count:  0 
 0 
 0 
 0 
 0 
 0 
 8 
 2 
 0 
 0 
Mean : 6.2000
===========================
WITH K = 100: 
Count:  0 
 0 
 0 
 0 
 0 
 4 
 50 
 42 
 4 
 0 
Mean : 6.4600
===========================
WITH K = 1000: 
Count:  0 
 0 
 0 
 0 
 0 
 95 
 511 
 353 
 41 
 0 
Mean : 6.3400
===========================
WITH K = 10000: 
Count:  0 
 0 
 0 
 0 
 0 
 978 
 5090 
 3575 
 357 
 0 
Mean : 6.3311
===========================*/





