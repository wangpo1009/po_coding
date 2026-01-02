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
  int pivot = right;
  right--;
  
  while(left <= right && left <= pivot){
    while(arr[pivot] < arr[right]){
      right--;
    }
    
    while(arr[pivot] > arr[left]){
      left++;
    }
    
    if(left < right){
      int temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
    
  }
  
  int temp = arr[left];
  arr[left] = arr[pivot];
  arr[pivot] = temp;
  
  return left;
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
  int freqTab[100] = {};
  int arr[MAX];
  
  
  for(int i = 0; i < 4; i++){
    
    for(int j = 0; j < 100; j++){
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
    for(int j = 0; j < 100; j++){
      printf(" %d \n", freqTab[j]);
    }
    float mn = mean(freqTab, 100, k[i]);
    printf("Mean : %.4f", mn);
    printf("===========================\n");
  }
  
  
  return 0;
}





