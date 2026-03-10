int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    (*returnSize) = 2;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));

    if(numbersSize == 2){
        result[0] = 1;
        result[1] = 2;
        return result;
    }

    int left = 0;
    int right = numbersSize - 1;
    while(left < right){
        if(numbers[right] + numbers[left] == target){
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }

        if(numbers[left] + numbers[right] > target){
            right--;
        }
        else{
            left++;
        }

    }
    return NULL;
}
