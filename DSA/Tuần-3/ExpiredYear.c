// Problem: Given an array of years, remove all the years that are greater than a given year k from the array.
// Then, compare the performance (swaps, comparisons, loops) between two approaches.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

void initializeArr(int year[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        year[i] = min + rand() % (max - min + 1);
    }
}

// --- Case A: Delete directly ---
void caseA(int year[], int *n, int k, int *swapA, int *compA, int *loopA) {
    *swapA = *compA = *loopA = 0;
    int indexWrite = 0;

    for (int i = 0; i < *n; i++) {
        (*loopA)++;
        (*compA)++;
        if (year[i] <= k) {
            year[indexWrite++] = year[i];
            (*swapA)++;
        }
    }
    *n = indexWrite;
}

// --- Case B: Sort then delete ---
void bubbleSort(int year[], int n, int *swapB, int *compB, int *loopB) {
    for (int i = n - 1; i > 0; i--) {
        (*loopB)++;
        for (int j = 0; j < i; j++) {
            (*loopB)++;
            (*compB)++;
            if (year[j] > year[j + 1]) {
                (*swapB)++;
                int temp = year[j];
                year[j] = year[j + 1];
                year[j + 1] = temp;
            }
        }
    }
}

void caseB(int year[], int *n, int k, int *swapB, int *compB, int *loopB) {
    *swapB = *compB = *loopB = 0;
    bubbleSort(year, *n, swapB, compB, loopB);

    int deleteYear = 0;
    for (int i = *n - 1; i >= 0 && year[i] > k; i--) {
        (*loopB)++;
        deleteYear++;
    }
    *n -= deleteYear;
}

void updateStats(int swap, int comp, int loop,
                 long long *sumSwap, long long *sumComp, long long *sumLoop,
                 int *minSwap, int *maxSwap, int *minComp, int *maxComp, int *minLoop, int *maxLoop) {
    *sumSwap += swap;
    *sumComp += comp;
    *sumLoop += loop;

    if (swap < *minSwap) *minSwap = swap;
    if (swap > *maxSwap) *maxSwap = swap;

    if (comp < *minComp) *minComp = comp;
    if (comp > *maxComp) *maxComp = comp;

    if (loop < *minLoop) *minLoop = loop;
    if (loop > *maxLoop) *maxLoop = loop;
}

int main() {
    srand(time(NULL));

    int year[MAX];
    int n, k = 2016, min = 1998, max = 2023;
    int swapA, compA, loopA;
    int swapB, compB, loopB;

    long long sumSwapA = 0, sumCompA = 0, sumLoopA = 0;
    long long sumSwapB = 0, sumCompB = 0, sumLoopB = 0;

    int minSwapA = 1e9, maxSwapA = 0;
    int minCompA = 1e9, maxCompA = 0;
    int minLoopA = 1e9, maxLoopA = 0;

    int minSwapB = 1e9, maxSwapB = 0;
    int minCompB = 1e9, maxCompB = 0;
    int minLoopB = 1e9, maxLoopB = 0;

    int testCount = 1000;

    for (int t = 0; t < testCount; t++) {
        // --- Case A ---
        n = 100;
        initializeArr(year, n, min, max);
        caseA(year, &n, k, &swapA, &compA, &loopA);
        updateStats(swapA, compA, loopA,
                    &sumSwapA, &sumCompA, &sumLoopA,
                    &minSwapA, &maxSwapA, &minCompA, &maxCompA, &minLoopA, &maxLoopA);

        // --- Case B ---
        n = 100;
        initializeArr(year, n, min, max);
        caseB(year, &n, k, &swapB, &compB, &loopB);
        updateStats(swapB, compB, loopB,
                    &sumSwapB, &sumCompB, &sumLoopB,
                    &minSwapB, &maxSwapB, &minCompB, &maxCompB, &minLoopB, &maxLoopB);
    }

    // --- In kết quả ---
    printf("===== STATISTICAL RESULTS AFTER %d TESTS =====\n", testCount);

    printf("CASE A (Delete directly):\n");
    printf("  Avg swaps: %.2f  | min=%d  | max=%d\n", sumSwapA / (double)testCount, minSwapA, maxSwapA);
    printf("  Avg comps: %.2f  | min=%d  | max=%d\n", sumCompA / (double)testCount, minCompA, maxCompA);
    printf("  Avg loops: %.2f  | min=%d  | max=%d\n", sumLoopA / (double)testCount, minLoopA, maxLoopA);

    printf("\nCASE B (Sort then delete):\n");
    printf("  Avg swaps: %.2f  | min=%d  | max=%d\n", sumSwapB / (double)testCount, minSwapB, maxSwapB);
    printf("  Avg comps: %.2f  | min=%d  | max=%d\n", sumCompB / (double)testCount, minCompB, maxCompB);
    printf("  Avg loops: %.2f  | min=%d  | max=%d\n", sumLoopB / (double)testCount, minLoopB, maxLoopB);

    return 0;
}

/*
===== STATISTICAL RESULTS AFTER 1000 TESTS =====
CASE A (Delete directly):
  Avg swaps: 73.23  | min=57  | max=86
  Avg comps: 100.00  | min=100  | max=100
  Avg loops: 100.00  | min=100  | max=100

CASE B (Sort then delete):
  Avg swaps: 2387.34  | min=1931  | max=2911
  Avg comps: 4950.00  | min=4950  | max=4950
  Avg loops: 5075.93  | min=5061  | max=5093
  
=>Seem like caseA is more effective
*/
