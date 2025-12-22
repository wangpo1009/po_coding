#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 200

float average(int arr[], int n, int testCount){
  float sum = 0;
  for(int i = 0; i < n; i++){
    sum += i*arr[i];
  }
  return sum / (float)testCount;
}

void initializeArr(int arr[], int n, int min, int max){
  for(int i = 0; i < n; i++){
    arr[i] = min + rand() % (max - min + 1);
  }
}

int maxProduct(int arr[], int n, int *step, int *assign){
  (*step) = 0;
  (*assign) = 0;
  int max = arr[0] * arr[1];
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int product = arr[i] * arr[j];
      (*step)++;
      if( product > max){
        (*assign)++;
        max = product;
      }
    }
  }
  return max;
}

int main()
{
  time_t t;
  srand((unsigned)time(&t));
  
  int n = 100;
  int arr[MAX];
  int step = 0;
  int assign = 0;
  //Problem a:
  printf("PROB 1:\n");
  initializeArr(arr, n, -100, 100);
  int max = maxProduct(arr, n, &step, &assign);
  printf("Step = %d\n", step);
  /*
  When n = 100;
  Step = 4950;
  So the number of step that calculate the product is equal to (n^2-n)/2,
with n is the size of the array;
  There is two loops, so the expected steps should equal so some quadratic func.
  */
  printf("\n==========================================\n\n");
  //Problem b:
  int testCount = 10000;
  int freq[MAX] = {};
  
  for(int i = 0; i < testCount; i++){
    initializeArr(arr, n, 1, 100);
    int max = maxProduct(arr, n, &step, &assign);
    freq[assign]++;
  }
  
  printf("PROB 2:\n");
  printf("< Frequency table >\n");
  printf("Oservation ------- Assignments\n");
  for(int i = 0; i < 60; i++){
    printf("%d --------------- %d \n",i, freq[i]);
  }
  printf("Mean = %.3f ", average(freq, 60, testCount));
  
  return 0;
}

/*
Output (n = 100):

PROB 1:
Step = 4950

==========================================

PROB 2:
< Frequency table >
Oservation ------- Assignments
0 --------------- 2 
1 --------------- 23 
2 --------------- 106 
3 --------------- 232 
4 --------------- 380 
5 --------------- 513 
6 --------------- 625 
7 --------------- 688 
8 --------------- 787 
9 --------------- 728 
10 --------------- 636 
11 --------------- 697 
12 --------------- 624 
13 --------------- 522 
14 --------------- 407 
15 --------------- 401 
16 --------------- 408 
17 --------------- 387 
18 --------------- 284 
19 --------------- 205 
20 --------------- 183 
21 --------------- 210 
22 --------------- 164 
23 --------------- 123 
24 --------------- 95 
25 --------------- 75 
26 --------------- 74 
27 --------------- 65 
28 --------------- 67 
29 --------------- 56 
30 --------------- 30 
31 --------------- 26 
32 --------------- 25 
33 --------------- 22 
34 --------------- 21 
35 --------------- 25 
36 --------------- 16 
37 --------------- 10 
38 --------------- 12 
39 --------------- 5 
40 --------------- 4 
41 --------------- 5 
42 --------------- 3 
43 --------------- 4 
44 --------------- 5 
45 --------------- 4 
46 --------------- 4 
47 --------------- 0 
48 --------------- 1 
49 --------------- 2 
50 --------------- 0 
51 --------------- 3 
52 --------------- 1 
53 --------------- 0 
54 --------------- 0 
55 --------------- 1 
56 --------------- 2 
57 --------------- 2 
58 --------------- 0 
59 --------------- 0 
Mean = 12.270
*/
