#include <stdio.h>
#define MAX 200

int chuoiLen(char chuoi[]){
    int len = 0;
    while(chuoi[len] != '\0'){
        len++;
    }
    return len;
}

void xoaPhanTu(char chuoi[], int viTriCanXoa){
    for(int i = viTriCanXoa; chuoi[i] != '\0'; i++){
        chuoi[i] = chuoi[i + 1];
    }    
    chuoi[chuoiLen(chuoi)];
}

int main() {
    char chuoi[MAX];
    printf("Nhap chuoi cua ban:\n");
    scanf("%s", chuoi);
    int viTriCanXoa;
    printf("Nhap vi tri can xoa:\n");
    scanf("%d",&viTriCanXoa);
    xoaPhanTu(chuoi, viTriCanXoa);
    printf("%s", chuoi);
    return 0;
}
