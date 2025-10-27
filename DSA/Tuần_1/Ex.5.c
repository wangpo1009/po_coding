#include <stdio.h>
#define MAX 200

void nhapMang(int soChuoi, int soKiTu, char mang[MAX][MAX]){
    for(int i = 0; i < soChuoi; i++){
        for(int j = 0; j < soKiTu; j++){
            scanf("%c", &mang[i][j]);
        }
        mang[i][soKiTu] = '\0';
        getchar();
    }
}

void xuatMang(int soChuoi, int soKiTu, char mang[MAX][MAX]){
    for(int i = 0; i < soChuoi; i++){
        printf("%s\n", mang[i]);
    }
}

void copyChuoi(char chuoiA[], char chuoiB[]){
    int len = 0;
    while(chuoiA[len] != '\0'){
        chuoiB[len] = chuoiA[len];
        len++;
    }
    chuoiB[len] = '\0';
}

void chenChuoi(int *soChuoi, int soKiTu, char mang[MAX][MAX], int viTriCanChen, char chuoiChen[]){
    (*soChuoi)++;
    for(int i = (*soChuoi) - 1;i > viTriCanChen; i--){
        copyChuoi(mang[i-1], mang[i]);
    }
    copyChuoi(chuoiChen, mang[viTriCanChen]);
}

int main() {
    char mang[MAX][MAX];
    int soChuoi;
    int soKiTu;
    scanf("%d",&soChuoi);
    getchar();
    scanf("%d",&soKiTu);
    getchar();
    printf("Nhap cac chuoi:\n");
    nhapMang(soChuoi, soKiTu, mang);
    printf("\n");
    chenChuoi(&soChuoi, soKiTu, mang, 1, "Khon");
    xuatMang(soChuoi, soKiTu, mang);

    return 0;
}
