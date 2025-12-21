#include <stdio.h>
#define MAX 100

void boInHoa(char a[]){
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] += 32;
        }
    }
}

int timChuCai(char a[], char kiTu){
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] == kiTu){
            return i;
        }
    }
    return -1;
}

int main(){
    char a[MAX];
    printf("Nhap chuoi cua ban:\n");
    scanf("%s", a);
    boInHoa(a);

    char kiTu;
    printf("Nhap ki tu can tim: ");
    scanf(" %c", &kiTu);  

    int index = timChuCai(a, kiTu);
    if(index != -1){
        printf("Tim thay '%c' tai vi tri: %d", kiTu, index);    
    }
    else{
        printf("Khong tim thay");
    }
    return 0;
}
/*
Output:
Nhap chuoi cua ban:
Phong
Nhap ki tu can tim: o
Tim thay 'o' tai vi tri: 2
*/
