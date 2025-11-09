//Problem: Given an array of years, remove all the years that are greater than a given year k from the array. Then, display statistical information.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
//delete all at once, only keep the 
void caseA(int year[], int *n, int k) {
  int indexWrite = 0;
  for (int i = 0; i < *n; i++) {
    if (year[i] <= k) {          
      year[indexWrite++] = year[i];      
    }
  }
  *n = indexWrite;                 
}

//sort then delete
void bubbleSort(int year[], int n) {
  for(int i = n-1; i > 0; i++){
    for(int j = 0; j < i; j++){
      if(year[j] > year[j+1]){
        int temp = year[j];
        year[j] = year[j+1];
        year[j+1] = temp;
      }
    }
  }
}

void caseB(int year[], int *n, int k){
  bubbleSort(year, (*n));
  int deleteYear = 0;
  for(int i = (*n) - 1; year[i] > k && i > 0; i--){
    deleteYear++;
  }
  (*n) -= deleteYear;
}

int main()
{
  int year[] = {2, 8, 4, 3, 6, 7, 3, 5, 1, 1};
  int n = 10;
  int k = 5;
  //caseA(year, &n, k);
  caseB(year, &n, k);
  
  for(int i = 0; i< n; i++){
    printf("%d ", year[i]);
  }
}
