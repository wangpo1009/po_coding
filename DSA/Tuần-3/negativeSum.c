
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

int negativeSum(int arr[], int n, int *ass){
    int sum = 0;
    (*ass) = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            (*ass)++;
            sum += arr[i];
        }
    }
    return sum;
}

void initializeArr(int arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }    
}

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

int main() {
    int arr[MAX];
    int n = 10;
    int min = -100;
    int max = 100;
    int k[] = {100, 1000, 1000000};
    int ass;
    
    time_t t;
    srand((unsigned)time(&t));
    
    printf("Frequency Table:\n");
    for(int i = 0; i < 3; i++){
        int freq[101] = {0};
        
        for(int j = 0; j < k[i]; j++){
            initializeArr(arr, n, min, max);
            int sum = negativeSum(arr, n, &ass);
            freq[ass]++;
        }
        
        float ave = average(freq, 13, k[i]);
        
        printf("k = %d\n", k[i]);
        printf("Comps\n");
        for(int j = 0; j < 13; j++){
            printf("%d\n", freq[j]);
        }
        printf("Mean = %.4f", ave);
        printf("====================================\n");
    }

    return 0;
}
/*
Frequency Table:
k = 100
Comps
0
0
2
10
21
21
27
14
3
2
0
0
0
Mean = 5.2500====================================
k = 1000
Comps
2
12
43
122
178
251
214
130
33
14
1
0
0
Mean = 5.0250====================================
k = 1000000
Comps
1077
9988
45236
119345
207542
246642
202782
114789
42265
9389
945
0
0
Mean = 4.9742====================================
*/
