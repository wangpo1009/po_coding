//Cho một dãy số thực có n phần tử và một số nguyên m. Tìm số có giá trị gần nhất với số m đã cho trong dãy.
#include <stdio.h>
#define MAX 100

void nhapMang(float a[], int *n){
    printf("Nhap so phan tu cua mang: \n");
    scanf("%d", n);
    printf("So phan tu cua mang la: %d\n", *n);
    printf("Nhap cac phan tu cua mang: \n");
    for(int i = 0; i < *n; i++){
        printf("Nhap a[%d]: ", i);
        scanf_s("%f", &a[i]);
    }
}

void xuatMang(float a[], int n){
    printf("Cac phan tu cua mang la:\n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", a[i]);
    }
}
int searchClosest(float a[], int n, int value){
    int closestIndex = -1;
    float minDiff = fabs(a[0] - (float)value);
    for(int i = 1; i < n; i++){
        float diff = fabs(a[i] - (float)value);
        if(diff < minDiff){
            minDiff = diff;
            closestIndex = i;
        }
    }
    return closestIndex;
}
int main(){
    float a[MAX] ;
    int n;
    printf("Bai tap 1, Chuong 1, Tu tuan 1\n");
    nhapMang(a, &n);
    int value;
    printf("Nhap gia tri:");
    scanf("%d", &value);
    int index = searchClosest(a, n, value);
    if(index != -1){
        printf("So gan nhat voi %d trong mang la: %.2f\n", value, a[index]);
    } else {
        printf("Khong the tim thay.\n");
    }
    return 0;
}
