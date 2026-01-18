#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArr(int arr[], int n, int min, int max) {
  for (int i = 0; i < n; i++) {
    arr[i] = min + rand() % (max - min + 1);
  }
}

void initializeAscendingArr(int arr[], int n, int min, int max){
  for (int i = 0; i < n; i++) {
    arr[i] = min + rand() % (max - min + 1)/4;
    min = arr[i];
  }
}

void initializeRandList(LinkedList *list, int n, int min, int max){
  if(n <= 0) return;

  for(int i = 0; i < n; i++){
    int value = min + rand() % (max - min + 1);
    insertEndList(list, value);
  }
}

void initializeRandTree(BinaryTree tree, int max, int min){
  for(int j = 0; j < MAX_NODE; j++){
    int data = MIN + rand() % (max - min + 1);
    tree.root = insertSearchTree(tree.root, data);
  }
}

float average(int arr[], int n, int k){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)i * arr[i];
    }    
    return sum/(float)k;
}

