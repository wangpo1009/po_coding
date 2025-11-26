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


    
int isZigzag(int a[], int n, int *comps){
    *comps = 0;
    // pattern 1: < > < > ...
    int ok1 = 1;
    for(int i = 0; i < n - 1; i++){
        (*comps)++;
        if(i % 2 == 0){ // chẵn: a[i] < a[i+1]
            if(a[i] >= a[i+1]){
                ok1 = 0;
                break;
            }
        } else {        // lẻ: a[i] > a[i+1]
            if(a[i] <= a[i+1]){
                ok1 = 0;
                break;
            }
        }
    }

    // pattern 2: > < > < ...
    int ok2 = 1;
    for(int i = 0; i < n - 1; i++){
        (*comps)++;
        if(i % 2 == 0){ // chẵn: a[i] > a[i+1]
            if(a[i] <= a[i+1]){
                ok2 = 0;
                break;
            }
        } else {        // lẻ: a[i] < a[i+1]
            if(a[i] >= a[i+1]){
                ok2 = 0;
                break;
            }
        }
    }

    return ok1 || ok2;
}


int main()
{
    time_t t;
    srand((unsigned)time(&t));
    
    int a[MAX];
    int n = 10;
    int min = -100;
    int max = 100;
    int freqTab[MAX] = {};
    int comps = 0;
    
    for(int i = 0; i < 1000; i++){
        initializeArr(a, n, min, max);
        isZigzag(a, n, &comps);
        freqTab[comps]++;
    }
    
     printf("Obseration\tComps\n");
    for(int i = 0; i < 15; i++){
      printf("%d\t%d\n",i, freqTab[i]);
    }
    printf("Mean = %f", mean(freqTab, 15, 1000));
    return 0;
    
}
