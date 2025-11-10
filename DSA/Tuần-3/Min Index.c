#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

int minIndex(int arr[], int n, int *comps){
    int index = 0;
    int min = arr[0];
    (*comps) = 0;
    for(int i = 0; i < n; i++){
        (*comps)++;
        if(arr[i] < min){
            index = i;
            min = arr[i];
        }
    }
    return index;
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
    int min = -20;
    int max = 20;
    int k[] = {100, 1000, 1000000};
    int comps;
    
    time_t t;
    srand((unsigned)time(&t));
    
    printf("Frequency Table:\n");
    for(int i = 0; i < 3; i++){
        int freq[101] = {0};
        
        for(int j = 0; j < k[i]; j++){
            initializeArr(arr, n, min, max);
            int index = minIndex(arr, n, &comps);
            freq[comps]++;
        }
        
        float ave = average(freq, 13, k[i]);
        
        printf("k = %d\n", k[i]);
        printf("Comps\n");
        for(int j = 0; j < 50; j++){
            printf("%d\n", freq[j]);
        }
        printf("Mean = %.4f", ave);
        printf("====================================\n");
    }

    return 0;
}
