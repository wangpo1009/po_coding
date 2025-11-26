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


    
int isMountain(int a[], int n, int *comps){
    int peakInd = 0;
    (*comps) = 0;
    for(int j = 0; j < n-1; j++){
        (*comps)++;
        if(a[j] < a[j+1]){
            peakInd = j + 1;
        }
        else{
            (*comps)++;
            if(a[j] == a[j+1]){
                return 0;
            }
            break;
        }
    }
    
    (*comps)++;
    if(peakInd == 0 || peakInd == n-1){
        return 0;
    }
    
    for(int i = peakInd; i < n-1; i++){
        (*comps)++;
        if(a[i+1] > a[i]){
            return 0;
        }
        (*comps)++;
        if(a[i] == a[i+1]){
            return 0;
        }
    }
    return 1;
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
        int k = isMountain(a, n, &comps);
        freqTab[comps]++;
    }
    
     printf("Obseration\tComps\n");
    for(int i = 0; i < 30; i++){
      printf("%d\t%d\n",i, freqTab[i]);
    }
    printf("Mean = %f", mean(freqTab, 30, 1000));
    return 0;
    
}
/*Obseration	Comps
0	0
1	0
2	7
3	501
4	1
5	0
6	0
7	195
8	84
9	106
10	49
11	34
12	11
13	9
14	2
15	1
16	0
17	0
18	0
19	0
Mean = 5.668000*/
