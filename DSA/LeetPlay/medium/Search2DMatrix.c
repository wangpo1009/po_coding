bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int left, right;

    left = 0;
    right = matrixSize * (*matrixColSize) - 1;

    while(left <= right){
        int mid = (left + right)/2;
        int val = matrix[mid / (*matrixColSize)][mid % (*matrixColSize)];
        if(val < target){
            left = mid + 1;
        }
        if(val > target){
            right = mid - 1;
        }
        if(val == target){
            return true;
        }
    }
    return false;
}
