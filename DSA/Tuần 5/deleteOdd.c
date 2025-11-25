#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initializeArr(int a[], int n, int min, int max){
  
  for(int i = 0; i < n; i++){
    a[i] = min + rand() % (max - min + 1);
  }
  
}

float mean(int a[], int n, int k){
  float sum = 0;
  for(int i = 0; i < n; i++){
    sum += (float)i * (float)a[i];
  }
  
  return sum / (float)k;
}

void deleteOdd(int a[], int *n, int *loops){
  (*loops) = 0;
  for(int i = (*n) - 1; i >= 0; i--){
    (*loops)++;
    if(a[i] % 2 == 1){
      for(int j = i; j < (*n) - 1; j++){
        (*loops)++;
        a[j] = a[j + 1];
      }
      (*n)--;
    }
    
  }
}
int main()
{
    time_t t;
    srand((unsigned)time(&t));
    
    int loops;
    int a[MAX];
    int n = 10;
    int min = 0;
    int max = 100;
    int freqTab[MAX] = {};
    
    for(int i = 0; i < 1000; i++){
      n = 10;
      initializeArr(a, n, min, max);
      deleteOdd(a, &n, &loops);
      freqTab[loops]++;
    }
    
    printf("Obseration\tLoops\n");
    for(int i = 0; i < 45; i++){
      printf("%d\t%d\n",i, freqTab[i]);
    }
    printf("Mean = %f", mean(freqTab, 45, 1000));
    
    return 0;
}

/*
Obseration	Loops
0	0
1	0
2	0
3	0
4	0
5	0
6	0
7	0
8	0
9	0
10	12
11	9
12	11
13	20
14	27
15	36
16	50
17	53
18	72
19	69
20	75
21	83
22	100
23	79
24	63
25	62
26	48
27	34
28	35
29	17
30	17
31	14
32	7
33	4
34	3
35	0
36	0
37	0
38	0
39	0
40	0
41	0
42	0
43	0
44	0
Mean = 21.200001*/

