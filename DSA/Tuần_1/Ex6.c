#include <stdio.h>
#define MAX 200

void chenSo(float mang[], int *doDai, int soViTriCanChen, int viTriCanChen[], float soCanChen[]){
    (*doDai) += soViTriCanChen;
    int index = soViTriCanChen;
    int i = *doDai-1; 
    int k = *doDai - soViTriCanChen - 1;
    while(index != 0){
        if( k == viTriCanChen[index - 1] ){
            mang[i] = mang[k];
            mang[k] = soCanChen[index - 1];
            i--;
            mang[i] = mang[k];
            index--;
        }
        else{
            mang[i] = mang[k];
        }
        i--;
        k--;
    }
}

int main() {
    float mang[MAX];
    int doDai;
    int soViTriCanChen;
    int viTriCanChen[MAX];
    float soCanChen[MAX];
    //Nhap mang goc
    printf("Nhap do dai mang cua ban:\n");
    scanf("%d",&doDai);
    printf("Nhap mang cua ban:\n");
    for(int i = 0; i < doDai; i++){
        scanf("%f", &mang[i]);
    }
    //Cac vi tri can chen ne
    printf("Nhap so luong can chen:\n");
    scanf("%d",&soViTriCanChen);
    printf("Nhap so va vi tri can chen:\n");
    for(int i = 0; i < soViTriCanChen; i++){
        scanf("%f%d",&soCanChen[i], &viTriCanChen[i]);
    }
    chenSo(mang, &doDai, soViTriCanChen, viTriCanChen, soCanChen);
    
    for(int i = 0; i < doDai; i++){
        printf("%.2f ", mang[i]);
    }
    
    return 0;
}
