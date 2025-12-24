#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertOrderedArray(float a[], int n, float value, int *assign) {
    if (n == 0 || a[n - 1] <= value) {
        (*assign)++;
        a[n] = value;
        return;
    }
    a[n] = a[n - 1];
    (*assign)++;
    insertOrderedArray(a, n - 1, value, assign);
}

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

void initializeArr(float a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
}
/*
Base case: xảy ra khi n = 0(tức là giá trị input vào là nhỏ nhất mảng) hoặc giá trị được chèn vào là lớn hơn giá trị tại vị trí đang xét;

Result of base case: chèn giá trị val cần chèn vào vị trí a[i]
=> Cụ thể ở đây là chèn val = 5 vào vị trí i = 5

Before base case: xảy ra khi:
+Tổng quát hóa a[i-1] > val : dời phần tử thứ i-1 sang phải -> basecase;
=> Cụ thể ở đây là khi xét đến insertOrderedArray(a,6,5) thực hiện
(1) so sánh a[6-1] <= val không? không.
(2) dời a[6] = a[6-1] (có giá trị tương ứng trong mảng là 6)
(3) sau đó gọi hàm insertOrderedArray(a,5,5)-> chèn giá trị vào mảng

Before before:
+Tổng quát hóa val < a[i-2]: dời phần tử thứ i-2 sang phải ->
-> dời phần tử thứ i-1 sang phải -> basecase;
=> Cụ thể ở đây là khi xét đến insertOrderedArray(a,7,5) thực hiện
(1) so sánh a[7-1] <= val không? không.
(2) dời a[7] = a[7-1] (có giá trị tương ứng trong mảng là 7)
(3) sau đó gọi hàm insertOrderedArray(a,6,5)
(4) so sánh a[6-1] <= val không? không.
(5) dời a[6] = a[6-1] (có giá trị tương ứng trong mảng là 6)
(6) sau đó gọi hàm insertOrderedArray(a,5,5)-> chèn giá trị vào mảng
*/

int main() {
 float a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int assign = 0;
 insertOrderedArray(a, 10, 5, &assign);
 printf("Số phép gán đã thực hiện là: %d\n", assign);
 //Số phép gán đã thực hiện là: 6
 
 time_t t;
 srand((unsigned)time(&t));
 int n = 10;
 int freqTab[11] = {};
 for(int i  = 0; i < 1000; i++){
    initializeArr(a,n);
    int val = rand()%10;
    int assign = 0;
    insertOrderedArray(a,n,val, &assign);
    freqTab[assign]++;
 }
 float meanAssign = average(freqTab, 11, 1000);
 printf("Số phép gán trung bình là: %.4f", meanAssign);
 //Số phép gán trung bình là: 5.3620
 return 0;
} 
