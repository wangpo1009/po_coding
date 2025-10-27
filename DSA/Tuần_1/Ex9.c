#include <stdio.h>
#define MAX 200

void xoaToaDo(float viTri[MAX][MAX], int *dong, int cot, float x, float y){
    int index = 0;
    for(int i = 0; i < *dong; i++){
        if(viTri[i][0] == x && viTri[i][1] == y){
            index = i;
        }
    }
    
    for(int i = index; i < *dong; i++){
        viTri[i][0] = viTri[i+1][0];
        viTri[i][1] = viTri[i+1][1];
        
    }
    (*dong)--;
}

int main() {
    int cot = 2;
    int dong;
    float viTri[MAX][MAX];
    printf("Nhap so toa do can nhap:");
    scanf("%d", &dong);
    for(int i = 0; i < dong; i++){
        for(int j = 0; j < cot; j++){
            scanf("%f", &viTri[i][j]);
        }
    }
    
    printf("Nhap toa do can xoa:");
    float x, y;
    scanf("%f%f",&x,&y);
    xoaToaDo(viTri, &dong, cot, x, y);
    for(int i = 0; i < dong; i++){
        for(int j = 0; j < cot; j++){
            printf("%.2f ", viTri[i][j]);
        }
        printf("\n");
    }
    return 0;
}
