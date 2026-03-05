typedef struct{
    int val;
    int freq;
}Count;

int compare(const void *a, const void *b){
    return (*(int*) a - *(int*) b);
}

int compareCount(const void *a, const void *b){
    Count *CountA = (Count *)a;
    Count *CountB = (Count *)b;
    return (CountB->freq - CountA->freq);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0) return NULL;
    if(numsSize == 1){
        (*returnSize) = 1;
        int* result = (int*)malloc(sizeof(int));
        result[0] = nums[0];
        return result;
    }

    Count* countArr = (Count*)malloc(sizeof(Count) * numsSize);
    int* result = (int*)malloc(sizeof(int) * k);

    qsort(nums, numsSize, sizeof(int), compare);
    
    int numOfVal = 0;
    for(int i = 0; i < numsSize; ){
        int start = i;
        countArr[numOfVal].val = nums[start];

        while(i < numsSize && nums[i] == nums[start]){
            i++;
        }
        countArr[numOfVal++].freq = i - start;
        start = i;
    }

    qsort(countArr, numOfVal, sizeof(Count), compareCount);

    for(int i = 0; i < k; i++){
        result[i] = countArr[i].val;
    }
    (*returnSize) = k;
    free(countArr);

    return result;
}
