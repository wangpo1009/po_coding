int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    int min;

    if(nums[right] > nums[left]) return nums[left];

    while(left < right){
        int mid = (left + right)/2;
        if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else{
            right = mid;
        } 
    }
    return nums[left];
}
