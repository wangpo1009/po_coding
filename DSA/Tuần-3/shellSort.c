#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 200

void shellSort(int a[], int n, int *shift, int *assign) {
  (*shift) = (*assign) = 0;
  for (int d = n/2; d > 0; d /= 2) {
    for (int i = d; i < n; i++) {
      (*assign)++;
      int t = a[i];
      int j;
      for (j = i; j >=d && a[j-d] > t; j -= d) {
        (*assign)++;
        (*shift)++;
        a[j] = a[j-d];
      }
      (*assign)++;
      a[j] = t;
    }
  }
}

int main() {
  int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
  int n = 20;
  int shift, assign;
  shellSort(a, n, &shift, &assign);
  for(int i = 0; i < n; i++){
    printf("%d ",a[i]);
  }
  printf("\nShift = %d \nAssign = %d", shift, assign);
  return 0;
}

/*
Output:

0 1 2 3 3 4 8 9 10 12 17 18 21 21 23 29 34 37 44 88 
Shift = 38 
Assign = 162
*/
