#include <stdio.h>

#define MAX 100

void printArrUsingRecursion(int arr[], int i){
  if(i == 0){
    return;
  }
  printArrUsingRecursion(arr, i - 1);
  printf("a[%d] = %d\n", i - 1, arr[i-1]);
}

int findElementWithRecursion(int arr[], int i, int value){
  if(arr[i] == value){
    return i;
  }
  
  if( i < 0){
    return -1;
  }
  
  findElementWithRecursion(arr, i+1, value);
}


int main(){
  int arr[] = {1, 0, 0, 9, 0, 6};
  printArrUsingRecursion(arr, 6);
  int el = findElementWithRecursion(arr, 0, 0);
  printf("%d", el);
  return 0;
}
