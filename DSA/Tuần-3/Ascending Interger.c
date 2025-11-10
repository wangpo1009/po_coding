#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 200

void extractNum(int num, int arr[]){
  int numLen = 4;
  while(num != 0){
    arr[--numLen] = num % 10;
    num /= 10;
  }
}

int increaseDigits(int arr[], int *comps){
  (*comps) = 0;
  for(int i = 0; i < 3; i++){
    (*comps)++;
    if(arr[i] > arr[i+1]){
      return -1;
    }
  }
  return 1;
}

float average(int arr[]){
  float sum = 0;
  for(int i = 0; i < 10; i++){
    sum += (float) i * (float) arr[i];
  }
  return sum / (float)9000;
}

int main()
{
  int numDigits[4];
  int comps = 0;
  int freq[MAX] = {};
  
  for(int num = 1000; num <= 9999; num++){
    extractNum(num, numDigits);
    int check = increaseDigits(numDigits, &comps);
    freq[comps]++;
  }
  
  printf("< FREQUENCY TABLE >\n");
  for(int i = 0; i < 5; i++){
    printf("Number of %d comps: %d\n", i, freq[i]);
  }
  printf("Mean = %.4f", average(freq));
  
  return 0;
}

/*
< FREQUENCY TABLE >
Number of 0 comps: 0
Number of 1 comps: 4500
Number of 2 comps: 2850
Number of 3 comps: 1650
Number of 4 comps: 0
Mean = 1.6833
*/
