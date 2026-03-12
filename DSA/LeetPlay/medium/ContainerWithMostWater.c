int calArea(int height1, int height2, int length){
    if(height1 < height2){
        return height1 * length;
    }
    return height2 * length;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = calArea(height[left], height[right], heightSize - 1);

    while(left < right){
        int current = calArea(height[left], height[right], (right - left));

        if(current > max) max = current;

        if(height[left] < height[right]) left++;
        else right--;
    }

    return max;
}
