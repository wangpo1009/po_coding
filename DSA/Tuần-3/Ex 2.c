#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 255

int cmp_int(const void *a, const void *b){
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

void initializeArray(int arr[], int n, int min, int max){
    int range = max - min + 1;
    if(range <= 0) range = 1;
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % range;
    }
    qsort(arr, n, sizeof(int), cmp_int);
}

int binarySearch(int arr[], int n, int value, int *loops){
    int lower = 0;
    int upper = n - 1;
    int mid;
    *loops = 0;
    while(lower <= upper){
        (*loops)++;
        mid = (lower + upper) / 2;
        if(value == arr[mid]){
            return mid;
        } else if(value < arr[mid]){
            upper = mid - 1;
        } else { // value > arr[mid]
            lower = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[MAX];
    int n = 10;
    int k[] = {100, 1000, 10000};
    int comps;
    
    srand((unsigned)time(NULL));
    
    for(int t = 0; t < 3; t++){
        int freqTab[11] = {0};
        for(int j = 0; j < k[t]; j++){
            initializeArray(arr, n, -1000, 1000);
            int chosenIndex = rand() % n;         
            int value = arr[chosenIndex];   
            int index = binarySearch(arr, n, value, &comps);
            if(index < 0) {
                continue;
            }
            if(comps >= 0 && comps <= 10)
                freqTab[comps]++;
            else {
                freqTab[10]++;
            }
        }
        
        float mean = 0.0f;
        for (int j = 0; j < 11; j++){
            mean += j * (float)freqTab[j];
        }
        mean /= k[t];
        
        printf("k = %d\n", k[t]);
        printf("comps: ");
        for (int j = 0; j < 11; j++) printf("%d ", j);
        printf("\nfrequ: ");
        for (int j = 0; j < 11; j++) printf("%d ", freqTab[j]);
        printf("\nMean = %.6f\n\n", mean);
    }
    return 0;

}
