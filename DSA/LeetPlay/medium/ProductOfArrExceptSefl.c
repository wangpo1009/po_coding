int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);

    // Bước 1: Tính tích các phần tử bên trái (Prefix)
    // result[i] sẽ chứa tích của tất cả các phần tử từ nums[0] đến nums[i-1]
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Bước 2: Nhân thêm tích các phần tử bên phải (Suffix)
    // Ta dùng một biến tạm 'right' để lưu tích dồn từ cuối mảng lên
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * right;
        right *= nums[i];
    }

    return result;
}
