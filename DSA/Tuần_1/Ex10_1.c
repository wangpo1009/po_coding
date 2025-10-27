#include <stdio.h>
#define MAX 200
int chuoiLen(char chuoi[]){
    int len = 0;
    while(chuoi[len] != '\0'){
        len++;
    }
    return len;
}

void timMaDoc(char chuoi[], char maDoc[], int *soLan, int viTri[]){
    int i = 0;
    int k = 0;
    int lenChuoi = chuoiLen(chuoi);
    int lenMaDoc = chuoiLen(maDoc);
    while(i < lenChuoi){
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
            i = i - k + 1; 
            k = 0;
        }
        }   
    }
}

int main() {
    char chuoi[MAX];
    printf("Nhap ma cua ban:\n");
    scanf("%s", chuoi);
    
    int soMaDoc;
    printf("Nhap so ma doc can tim:\n");
    scanf("%d", &soMaDoc);
    int soLan = 0;
    int viTriMaDoc[MAX];
    
    timMaDoc(chuoi, "hhg", &soLan, viTriMaDoc);
    
    printf("%d  %d",soLan, viTriMaDoc[soLan - 1]);
    
    
    return 0;
}
