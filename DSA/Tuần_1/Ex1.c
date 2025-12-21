#include <stdio.h>
#include <math.h>

#define MAX 100

void xuatMang(float a[], int n){
    printf("Cac phan tu cua mang la:\n");
    for(int i = 0; i < n; i++){
        printf("%.2f ", a[i]);
    }
}
int searchClosest(float a[], int n, float value){
    int closestIndex = 0;
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
    float a[] = {1, 2, -4, 8, 9, 10, 4, 5, -2, 7};
    int n = 10;
    float value = 9.7;
    scanf("%d", &value);
    int index = searchClosest(a, n, value);
    if(index != -1){
        printf("So gan nhat voi %.2f trong mang la: %.2f\n", value, a[index]);
    } else {
        printf("Khong the tim thay.\n");
    }
    return 0;
}

/*
Output:
So gan nhat voi 9.70 trong mang la: 10.00
*/
