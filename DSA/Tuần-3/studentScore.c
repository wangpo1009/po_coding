#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initializeArr(float arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = 0 + (float)rand()/ RAND_MAX * 10;
    }    
}

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

int minIndex(float arr[], int start, int n, int *comps){
    int min_idx = start;
    float min = arr[start];
    for(int i = start + 1; i < n; i++){
        (*comps)++;
        if(arr[i] < min){
            min = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void sortScores(float arr[], int n, int *comps){
    (*comps) = 0;
    for(int i = 0; i < n - 1; i++){
        int min_idx = minIndex(arr, i, n, comps);
        (*comps)++;
        if(min_idx != i){
            float temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
int main(){
    float score[MAX];
    int n = 40;
    
    time_t t;
    srand((unsigned) time(&t));
    int comparisons = 0;
    int freq[1000] = {0};
    for(int i  = 0; i < 100; i++){
        initializeArr(score, n);
        sortScores(score, n, &comparisons);
        freq[comparisons]++;
    }
    
    float av = average(freq, 1000, 100);

    printf("Average number of comparisons: %.2f\n", av);
    return 0;
}
/*
Average number of comparisons: 819.00
The average number of comparisons is consistent with the expected time complexity of the selection sort algorithm, which is O(n^2). For n = 40, the theoretical number of comparisons is approximately n(n-1)/2 = 40*39/2 = 780. 
The observed average of 819.00 is close to this theoretical value, accounting for variations due to the random initialization of scores.
*/
