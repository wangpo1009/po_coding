#include <stdio.h>
#define MAX 1009

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

void quickSort(int arr[], int left, int right){
  if(left < right){
    int piv = partition(arr, left, right);
    quickSort(arr, left, piv - 1);
    quickSort(arr, piv + 1, right);
  }
  return;
}

int main()
{
  int arr[] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9, -2};
  int n = 11;
  quickSort(arr, 0, n-1);
  for(int i = 0; i < 11; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
