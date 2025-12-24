
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

void initializeArr(int a[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        a[i] = min + rand()%(max - min + 1);
    }
}

int max(int a[], int n, int *assign) {
    if (n == 1){
        return a[n-1];
    }
    (*assign)++;
    int maxValue = max(a, n-1, assign);
    
    if (a[n-1] > maxValue){
        (*assign)++;
        maxValue = a[n-1];
    }
    return maxValue;
} 

/*
Base case: Xảy ra khi n = 1;

Result of base case: Trả về giá trị a[n-1] tức là a[0]

Before base case: Xảy ra khi n = 2;
(1)Chương trình thực hiện gọi hàm max(a, 2)
(2)So sánh n = 1 không? Không.
(2)Chương trình gọi hàm max(a,1) rồi gán vào maxValue (base case) (maxVal = a[0] = 2)
(3)Chương trình thực hiện so sảnh maxValue với a[1] = 5. Thấy có a[1] lớn hơn nên gán maxValue = a[1] (= 5);

Before before: Xảy ra khi n = 3:
(1)Chương trình thực hiện gọi hàm max(a, 3)
(2)So sánh n = 1 không? Không.
(2)Chương trình gọi hàm max(a,2):
    (1')So sánh n = 1 không? Không.
    (2')Chương trình gọi hàm max(a,1) rồi gán vào maxValue (base case) (maxVal = a[0] = 2)
    (3')Chương trình thực hiện so sảnh maxValue với a[1] = 5. Thấy có a[1] lớn hơn nên gán maxValue = a[1] (= 5);
(3)Chương trình thực hiện so sảnh maxValue với a[2] = 7. Thấy có a[2] lớn hơn (7 > 5) nên gán maxValue = a[2] (= 7);

*/

int main() {
    int a[] = {2, 5, 7, 0, 12, 1, 4};
    int assign = 0;
    printf("Max of arr: %d\n", max(a, 7, &assign));
    printf("Number of assignment occurred: %d\n", assign);
 /*
    Max of arr: 12
    Number of assignment occurred: 9
 
 */
    time_t t;
    srand((unsigned)time(&t));
    int n = 10;
    int minimum = 0;
    int maximum = 100;
    int b[MAX];
    int freqTab[100] = {};
    for(int i  = 0; i < 1000; i++){
        initializeArr(b, n, minimum, maximum);
        int assign = 0;
        int maxElement = max(b, n, &assign);
        freqTab[assign]++;
    }
     
    float meanAssign = average(freqTab, 100, 1000);
    printf("Số phép gán trung bình là: %.4f", meanAssign);
    return 0;
} 
/*
    Số phép gán trung bình là: 10.8450
*/
