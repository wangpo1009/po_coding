#include <stdio.h>

#define MAX 100


void sort(int arr[], int n){
   for(int i = 0; i < n; i++){
     
    int minInd = i;
    
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[minInd]){
        minInd = j;
      }
    }
    
    if(minInd != i){
      int temp = arr[i];
      arr[i] = arr[minInd];
      arr[minInd] = temp;
    }
    
  }    
}

int main()
{
    int n = 11;
    int arr[MAX] = {1, 9, 2, 3, 5, 3, 7, 1, 2, 3, 6};
    sort(arr,n);
    
    for(int  i = 0; i < n; i++){
      printf("%d ", arr[i]);
    }
    return 0;
}
