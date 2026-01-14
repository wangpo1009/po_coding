/*
Câu 1: Hãy viết hàm kiểm tra xem một mảng số nguyên N phần tử có chứa một cặp số mà có tổng bằng 10 hay không.Ví dụ, mảng [1, 2, 3, 4, 5, 6] có 4 và 6 là cặp số có tổng bằng 10. 
Hãy tính số bước của hàm trên theo N trong các trường hợp tốt nhất và xấu nhất. Biểu diễn trường hợp xấu nhất theo thuật ngữ Big O.

*/
int findSum_10(int arr[], int arrSize){
  int pair = 0;
  for(int i = 0; i < arrSize; i++){
    for(int j = i + 1; j < arrSize; j++){
      if(arr[i] + arr[j] == 10){
        return 1;//found
      }
    }
  }
  return 0;//not found
}
/*
best case: the first and second elements of the arr sum to 10: need 1 step (O(1))
worst case: only the two last elements in the arr sum up to 10: need n(n+1)/2 steps (O(n^2))
*/
