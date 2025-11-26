#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initializeArr(char a[], int n, int min, int max){
  
  for(int i = 0; i < n; i++){
    a[i] =(char) (min + rand() % (max - min + 1));
  }
  a[n] = '\0';
}

float mean(int a[], int n, int k){
  float sum = 0;
  for(int i = 0; i < n; i++){
    sum += (float)i * (float)a[i];
  }
  
  return sum / (float)k;
}

int chuoiDoiXung(char arr[], int n, int *comps){
  int left = 0;
  int right = n-1;
  (*comps) = 0;
  while(left <= right){
    (*comps)++;
    if(arr[left] == arr[right]){
      left++;
      right--;
    }
    else{
      return 0;
    }
  }
  return 1;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    
    int comps = 0;
    char a[MAX] ;
    int min = 97;
    int max = 122;
    int n = 11;
    int k = 100000;
    int freqTab[MAX] = {};
    
    for(int i = 0; i < k; i++){
      initializeArr(a, n, min, max);
      int k = chuoiDoiXung(a, n, &comps);
      freqTab[comps]++;
    }
    
    printf("Obseration\tComps\n");
    for(int i = 0; i < 10; i++){
      printf("%d\t\t%d\n",i, freqTab[i]);
    }
    printf("Mean = %f", mean(freqTab, n, k));
    
    return 0;
}

/*
Obseration      Comps
0               0
1               96187
2               3661
3               144
4               8
5               0
6               0
7               0
8               0
9               0
Mean = 1.039730

Trong trường hợp xấu nhất, tức là chuỗi đối xứng thật thì ta phải duyệt qua n/2 phần tử;
=> số comps = n/2
Trong trường hợp tốt nhất, tức là chuỗi có phần tử đầu và cuối khác nhau thì ta chỉ cần duyệt 1 lần;
=> số comps = 1;
Vậy theo big(O) thì thuật toán có độ phức tạp là O(N) với N là độ dài của chuỗi ban đầu
*/
