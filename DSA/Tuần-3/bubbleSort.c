#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

/*Nhận thấy: 
-khi chạy n = 10 -> tất cả lần chạy đều rơi vào trường hợp comps = 45
-khi chạy n = 20 -> tất cả lần chạy đều rơi vào trường hợp comps = 190

Có vẻ không cần đến mảng tần số vì thuật toán bubbleSort có số lần so sánh chỉ phụ thuộc vào độ lớn của mảng. Nên ta không cần lập bảng tần số mà chỉ đơn thuần cần đếm số lần so sánh mà thôi.

Frequency Table:
When n = 10
k = 100
Comps = 45
k = 1000
Comps = 45
k = 10000
Comps = 45
<==========================================>
When n = 20
k = 100
Comps = 190
k = 1000
Comps = 190
k = 10000
Comps = 190
<==========================================>
When n = 30
k = 100
Comps = 435
k = 1000
Comps = 435
k = 10000
Comps = 435
<==========================================>
When n = 40
k = 100
Comps = 780
k = 1000
Comps = 780
k = 10000
Comps = 780
<==========================================>
When n = 50
k = 100
Comps = 1225
k = 1000
Comps = 1225
k = 10000
Comps = 1225
<==========================================>
When n = 60
k = 100
Comps = 1770
k = 1000
Comps = 1770
k = 10000
Comps = 1770
<==========================================>
When n = 70
k = 100
Comps = 2415
k = 1000
Comps = 2415
k = 10000
Comps = 2415
<==========================================>
When n = 80
k = 100
Comps = 3160
k = 1000
Comps = 3160
k = 10000
Comps = 3160
<==========================================>
When n = 90
k = 100
Comps = 4005
k = 1000
Comps = 4005
k = 10000
Comps = 4005
<==========================================>
When n = 100
k = 100
Comps = 4950
k = 1000
Comps = 4950
k = 10000
Comps = 4950
<==========================================>

Dựa trên thí nghiệm trên ta có thể thấy số lần so sánh comps = n*(n-1)/2 với n là kích thước của mảng. Vậy độ phức tạp và thời gian của thuật toán là một hàm bậc 2 so với kích thước của mảng. => O(n^2).
*/
void bubbleSort(int arr[], int n, int *comps){
    (*comps) = 0;
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            (*comps)++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void initializeArr(int arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }    
}

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

int main() {
    int arr[MAX];
    int n[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int min = -100;
    int max = 100;
    int k[] = {100, 1000, 10000};
    int comps;
    
    time_t t;
    srand((unsigned)time(&t));
    
    printf("Frequency Table:\n");
    for(int m = 0; m < 10; m++){
        printf("When n = %d\n", n[m]);
        for(int i = 0; i < 3; i++){
            int freq = 0;
        
            for(int j = 0; j < k[i]; j++){
                initializeArr(arr, n[m], min, max);
                bubbleSort(arr, n[m], &comps);
                freq++;
            }
        
            printf("k = %d\n", k[i]);
            printf("Comps = %d\n", comps);
        }
        printf("<==========================================>\n");
    }
    return 0;
}
