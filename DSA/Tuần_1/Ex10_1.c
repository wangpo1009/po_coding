#include <stdio.h>
#define MAX 1000

int chuoiLen(char chuoi[]){
    int len = 0;
    while(chuoi[len] != '\0'){
        len++;
    }
    return len;
}

void timMotMaDoc(char chuoi[], char maDoc[], int *soLan, int viTri[]){
    int i = 0;
    int k = 0;
    int lenChuoi = chuoiLen(chuoi);
    int lenMaDoc = chuoiLen(maDoc);
    while (i < lenChuoi) {
        if (chuoi[i] == maDoc[k]) {
            i++;
            k++;
            if (k == lenMaDoc) { 
                viTri[*soLan] = i - k;
                (*soLan)++;
                k = 0;
            }
        } 
        else {
            i++;
            k = 0;
        }
    }   
}

void timNhieuMaDoc(char chuoi[], char maDoc[MAX][MAX], int soLan[], int soMaDoc, int viTri[MAX][MAX]){
    int i = 0;
    while( i < soMaDoc){
        soLan[i] = 0;
        timMotMaDoc(chuoi, maDoc[i], &soLan[i], viTri[i]);
        i++;
    }
}
int main() {
    char chuoi[MAX];
    printf("Nhap ma cua ban:\n");
    scanf("%s", chuoi);
    
    int soMaDoc;
    printf("Nhap so ma doc can tim:\n");
    scanf("%d", &soMaDoc);
    char maDoc[MAX][MAX];
    printf("Nhap cac ma doc:\n");
    for(int i = 0; i < soMaDoc; i++){
        scanf("%s", maDoc[i]);
    }
    
    int soLan[MAX];
    int viTriMaDoc[MAX][MAX];
    
    timNhieuMaDoc(chuoi, maDoc, soLan, soMaDoc, viTriMaDoc);
    
    for(int i = 0; i < soMaDoc; i++){
        if(soLan[i] != 0){
            printf("tim thay %d ma %s tai cac vi tri: ", soLan[i], maDoc[i]);
            for(int j = 0; j < soLan[i]; j++){
                printf("%d ", viTriMaDoc[i][j]);
            }
            printf("\n");
        }
        else{
            printf("tim thay %d ma %s\n ", soLan[i], maDoc[i]);
        }
    }
    return 0;
}
