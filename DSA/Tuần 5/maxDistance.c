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

int distance(int x, int y){
  if(x > y){
    return x - y;
  }
  return y - x;
}

int maxDistance(int a[], int n, int p, int *assigns){
  int maxDist = distance(a[0], p);
  int maxInd = 0;
  (*assigns) = 0;
  
  for(int i = 0; i < n; i++){
    if(distance(a[i], p) >= maxDist){
      (*assigns)++;
      maxDist = distance(a[i], p);
      maxInd = i;
    }
  }
  
  return maxDist;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    
    int assigns;
    int a[MAX];
    int n = 10;
    int min = -1000;
    int max = 1000;
    int freqTab[MAX] = {};
    
    for(int i = 0; i < 1000; i++){
      initializeArr(a, n, min, max);
      int p = a[rand() % 10];
      int res = maxDistance(a, n, p, &assigns);
      freqTab[assigns]++;
      
    }
    
    printf("Observation\tAssignments\n");
    for(int i = 0; i < 11; i++){
      printf("%d\t\t%d\n",i, freqTab[i]);
    }
    printf("meanComps = %f\n", mean(freqTab, 100, 1000));
    
}

/*
Observation	Assignments
0		0
1		91
2		308
3		306
4		196
5		79
6		14
7		6
8		0
9		0
10		0
meanComps = 2.930000
*/
