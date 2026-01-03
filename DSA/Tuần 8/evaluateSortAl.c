#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 255


void initializeArr(int arr[], int n){
  for(int i = 0; i < n; i++){
    arr[i] = rand() % MAX;
  }
}

//some function to print freqTab 

void printLine(){
    printf("+-----------+-------------------------+---------------------+\n");
}

void printHeader(){
  printLine();
  printf("| %-14s | %-8s | %-8s | %-8s | %-8s |\n",
         "Algorithm", "Case (a)", "Case (b)", "Case (c)", "Case (d)");
  printLine();
}

typedef void (*SortFunc)(int[], int, int*);

void quickSortWrapper(int arr[], int n, int* comps){
    *comps = 0;
    quickSort(arr, 0, n - 1, comps);
}

void printAlgorithmRow(char name[], SortFunc sort, int arr[4][MAX], int n[4]){
    int comps[4];

    for(int i = 0; i < 4; i++){
        int temp[MAX];

        for(int j = 0; j < n[i]; j++)
            temp[j] = arr[i][j];

        comps[i] = 0;
        sort(temp, n[i], &comps[i]);
    }

    printf("| %-14s | C=%-5d | C=%-5d | C=%-5d | C=%-5d |\n",
           name, comps[0], comps[1], comps[2], comps[3]);

    printLine();
}

// <=========================== QuickSort ===============================>
int partition(int arr[], int left, int right, int* comps){
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
      (*comps)++;
      if(arr[j] <= pivot){
        i++;
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

void quickSort(int arr[], int left, int right, int* comps){
  (*comps)++;
  if(left < right){
    int piv = partition(arr, left, right, comps);
    quickSort(arr, left, piv-1, comps);
    quickSort(arr, piv+1, right, comps);
  }
  return ;
}

//<============================ BubbleSort ==============================>
void bubbleSort(int arr[], int n, int* comps){
  (*comps)++;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-i-1; j++){
      
      (*comps)++;
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        
      }
    }
  }
}


//<============================ Insertion Sort ==============================>
void insertionSort(int arr[], int n, int *comps){
  (*comps) = 0;
  for(int i = 1; i < n; i++){
    
    int key = arr[i];
    int j = i - 1;
    
    while(j >= 0){
      (*comps)++;
      
      if(arr[j] > key){
        arr[j+1] = arr[j];
        j--;
      }
      else{
        break;
      }
      
    }
    
    arr[j + 1] = key;
    
  }
}

//<============================ Selection Sort ==============================>
void selectionSort(int arr[], int n, int *comps){
  (*comps) = 0;
  
  for(int i = 0; i < n; i++){
    
    int minInd = i;
    
    for(int j = i + 1; j < n; j++){
      (*comps)++;
      if(arr[j] < arr[minInd]){
        minInd = j;
      }
    }
    
    if(minInd != i){
      int temp = arr[i];
      arr[i] = arr[minInd];
      arr[minInd] = temp;
    }
    
  }  
  
}



int main(){
  time_t t;
  srand((unsigned)time(&t));
  
  //The array lengths corresponding to each case (a, b, c, and d)
  int n[4] = {5, 10, 20, 20};
  //The array corresponding to each case (a, b, c, and d)
  int arr[4][MAX] = {
    {3, 2, 9, 7, 5},
    {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    {4, 3, 2, 6, 5, -3, 5, 7, -3, 1, -3, 5, 7, 9, 7, -5, 3, 2, 1, 2},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20}
  };
  int compsQuick, compsBubble, compsSelection, compsInsertion;
  compsQuick = compsInsertion = compsSelection = compsBubble = 0;
  
  int freqTab[4][50] = {};
  

  //printing things
  printHeader();
  printAlgorithmRow("Bubble Sort", bubbleSort, arr, n);
  printAlgorithmRow("Insertion", insertionSort, arr, n);
  printAlgorithmRow("Selection", selectionSort, arr, n);
  printAlgorithmRow("Quick Sort", quickSortWrapper, arr, n);
 
  return 0;
}
/*
Output:

+-----------+-------------------------+---------------------+
| Algorithm      | Case (a) | Case (b) | Case (c) | Case (d) |
+-----------+-------------------------+---------------------+
| Bubble Sort    | C=11    | C=46    | C=191   | C=191   |
+-----------+-------------------------+---------------------+
| Insertion      | C=7     | C=45    | C=109   | C=27    |
+-----------+-------------------------+---------------------+
| Selection      | C=10    | C=45    | C=190   | C=190   |
+-----------+-------------------------+---------------------+
| Quick Sort     | C=13    | C=64    | C=88    | C=167   |
+-----------+-------------------------+---------------------+

*/
