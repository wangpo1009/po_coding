#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 255

void insertionSort(int arr[], int n, int *comps, int *shifts){
  (*comps) = (*shifts) = 0;
  for(int i = 1; i < n; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0){
      (*comps)++;
      if(arr[j] > key){
        (*shifts)++;
        arr[j+1] = arr[j];
        j--;
      }
      else{
        break;
      }
    }
    arr[j + 1] = key;
    (*shifts)++;
  }
}

void selectionSort(int arr[], int n, int *comps, int *swaps){
  (*comps) = (*swaps) = 0;
  for(int i = 0; i < n; i++){
    int minInd = i;
    for(int j = i + 1; j < n; j++){
      (*comps)++;
      if(arr[j] < arr[minInd]){
        minInd = j;
      }
    }
    if(minInd != i){
      (*swaps)++;
      int temp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = temp;
    }
  }    
}

void initializeArr(int arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
        arr[i] = min + rand() % (max - min + 1);
    }    
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int arr[MAX];
    int n = 10;
    int min = -100;
    int max = 100;
    int k[4] = {100, 1000, 10000, 100000};
    
    int selectionComps, selectionSwaps;
    int insertionComps, insertionShifts;
    for(int i = 0; i < 4; i++){
      int insertionFreqTab[2][51] = {};
      int selectionFreqTab[2][51] = {};
      
      printf("K = %d\n", k[i]);
      for(int j = 0; j < k[i]; j++){
        initializeArr(arr, n, min, max);
        selectionSort(arr, n, &selectionComps, &selectionSwaps);
        selectionFreqTab[0][selectionComps]++;
        selectionFreqTab[1][selectionSwaps]++;
        
        initializeArr(arr, n, min, max);
        insertionSort(arr, n, &insertionComps, &insertionShifts);
        insertionFreqTab[0][insertionComps]++;
        insertionFreqTab[1][insertionShifts]++;
      }
      
      printf("\t\tSelection\t||\tInsertion\n");
      printf("Observations|\tComps\tSwaps\t||\tComps\tShifts\n");
      for(int j = 1; j < 51; j++){
        printf("%d\t\t%d\t%d\t\t%d\t%d\n", j, selectionFreqTab[0][j], selectionFreqTab[1][j], insertionFreqTab[0][j], insertionFreqTab[1][j]);
      }
      printf("===============================\n");
    }
    
    return 0;
}
/*
K = 100
        Selection    ||    Insertion
Observations|    Comps    Swaps    ||    Comps    Shifts
0        0    0        0    0
1        0    0        0    0
2        0    0        0    0
3        0    1        0    0
4        0    2        0    0
5        0    9        0    0
6        0    22        0    0
7        0    35        0    0
8        0    21        0    0
9        0    10        0    0
10        0    0        0    0
11        0    0        0    0
12        0    0        0    0
13        0    0        0    0
14        0    0        0    0
15        0    0        0    0
16        0    0        0    0
17        0    0        0    0
18        0    0        1    0
19        0    0        0    1
20        0    0        3    0
21        0    0        3    3
22        0    0        1    2
23        0    0        1    0
24        0    0        7    3
25        0    0        3    6
26        0    0        8    5
27        0    0        6    6
28        0    0        8    5
29        0    0        11    6
30        0    0        12    7
31        0    0        4    9
32        0    0        7    10
33        0    0        5    6
34        0    0        5    6
35        0    0        5    3
36        0    0        3    7
37        0    0        2    1
38        0    0        2    3
39        0    0        2    3
40        0    0        0    3
41        0    0        0    2
42        0    0        1    1
43        0    0        0    1
44        0    0        0    0
45        100    0        0    1
46        0    0        0    0
47        0    0        0    0
48        0    0        0    0
49        0    0        0    0
50        0    0        0    0
===============================
K = 1000
        Selection    ||    Insertion
Observations|    Comps    Swaps    ||    Comps    Shifts
0        0    0        0    0
1        0    0        0    0
2        0    0        0    0
3        0    1        0    0
4        0    24        0    0
5        0    76        0    0
6        0    212        0    0
7        0    339        0    0
8        0    248        0    0
9        0    100        0    0
10        0    0        0    0
11        0    0        0    0
12        0    0        0    0
13        0    0        0    0
14        0    0        0    0
15        0    0        2    1
16        0    0        2    2
17        0    0        2    2
18        0    0        4    0
19        0    0        10    6
20        0    0        15    8
21        0    0        19    17
22        0    0        29    17
23        0    0        48    19
24        0    0        37    39
25        0    0        52    42
26        0    0        61    30
27        0    0        62    61
28        0    0        67    58
29        0    0        76    68
30        0    0        87    67
31        0    0        84    67
32        0    0        71    77
33        0    0        67    64
34        0    0        54    69
35        0    0        41    68
36        0    0        36    51
37        0    0        38    43
38        0    0        17    30
39        0    0        9    32
40        0    0        3    31
41        0    0        3    13
42        0    0        1    8
43        0    0        2    3
44        0    0        0    2
45        1000    0        1    1
46        0    0        0    2
47        0    0        0    1
48        0    0        0    0
49        0    0        0    0
50        0    0        0    0
===============================
K = 10000
        Selection    ||    Insertion
Observations|    Comps    Swaps    ||    Comps    Shifts
0        0    0        0    0
1        0    0        0    0
2        0    4        0    0
3        0    25        0    0
4        0    215        0    0
5        0    759        0    0
6        0    2026        0    0
7        0    3168        0    0
8        0    2822        0    0
9        0    981        0    0
10        0    0        0    0
11        0    0        0    0
12        0    0        1    1
13        0    0        1    0
14        0    0        3    2
15        0    0        6    3
16        0    0        19    6
17        0    0        40    21
18        0    0        60    37
19        0    0        102    62
20        0    0        135    91
21        0    0        215    142
22        0    0        279    182
23        0    0        371    268
24        0    0        469    321
25        0    0        527    390
26        0    0        580    470
27        0    0        707    519
28        0    0        731    558
29        0    0        781    664
30        0    0        785    713
31        0    0        715    705
32        0    0        680    683
33        0    0        625    663
34        0    0        500    626
35        0    0        460    560
36        0    0        370    448
37        0    0        261    452
38        0    0        221    367
39        0    0        149    286
40        0    0        91    216
41        0    0        64    182
42        0    0        29    133
43        0    0        16    83
44        0    0        7    63
45        10000    0        0    35
46        0    0        0    26
47        0    0        0    8
48        0    0        0    13
49        0    0        0    1
50        0    0        0    0
===============================
K = 100000
        Selection    ||    Insertion
Observations|    Comps    Swaps    ||    Comps    Shifts
0        0    0        0    0
1        0    2        0    0
2        0    29        0    0
3        0    273        0    0
4        0    1833        0    0
5        0    7651        0    0
6        0    20359        0    0
7        0    32069        0    0
8        0    28001        0    0
9        0    9783        0    0
10        0    0        1    0
11        0    0        3    2
12        0    0        9    9
13        0    0        26    7
14        0    0        51    34
15        0    0        140    74
16        0    0        261    150
17        0    0        381    248
18        0    0        677    390
19        0    0        1042    665
20        0    0        1515    955
21        0    0        2057    1335
22        0    0        2787    1922
23        0    0        3705    2527
24        0    0        4361    3055
25        0    0        5162    3893
26        0    0        6121    4555
27        0    0        6720    5102
28        0    0        7299    5983
29        0    0        7463    6409
30        0    0        7602    6820
31        0    0        7405    6892
32        0    0        6870    6857
33        0    0        6310    6643
34        0    0        5521    6225
35        0    0        4607    5757
36        0    0        3701    5118
37        0    0        2781    4382
38        0    0        2072    3624
39        0    0        1370    3006
40        0    0        949    2283
41        0    0        548    1690
42        0    0        296    1194
43        0    0        134    845
44        0    0        47    578
45        100000    0        6    348
46        0    0        0    210
47        0    0        0    111
48        0    0        0    63
49        0    0        0    28
50        0    0        0    10
===============================
*/
