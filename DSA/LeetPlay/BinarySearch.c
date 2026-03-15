int search(int* nums, int numsSize, int target) {
    int lower = 0;
    int upper = numsSize - 1;
    int mid;
    while(lower <= upper){
        mid = (lower + upper) / 2;
        if(target == nums[mid]){
            return mid;
        } else if(target < nums[mid]){
            upper = mid - 1;
        } else { // value > arr[mid]
            lower = mid + 1;
        }
    }
    return -1;
}
