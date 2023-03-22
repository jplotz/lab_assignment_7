/*
 * Jacob Plotz
 * COP 3502 Torosdagli
 * Lab Assignment 7
 * 22 Mar. 2023
 */

#define FALSE 0
#define TRUE !FALSE

#include <stdio.h>
#include <stdlib.h>

void findSwapsPerIndex(int arr[], int len);
void printArray(int arr[], int len);
void swap(int *a, int *b);

int main(void)
{
    int exampleArray[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int exampleArrayLen = 9;
    findSwapsPerIndex(exampleArray, exampleArrayLen);
    return 0;
}

// assume for this problem that "index" refers to the position
// of a specific value in the original unsorted array, and counting
// the "number of swaps for each index" refers to counting how many
// times each value in the original unsorted array must be swapped
// during the bubble sort algorithm
void findSwapsPerIndex(int arr[], int len)
{
    int *numSwapsPerIndex = calloc(len, sizeof(int));
    int totalSwapsCnt = 0;

    printf("Unsorted Array:\n\t");
    printArray(arr, len);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                totalSwapsCnt++;
                numSwapsPerIndex[i]++;
            }
        }
    }

    printf("Number of Swaps Per Each Index:\n");
    for (int i = 0; i < len; i++)
        printf("\t%d: %d\n", i, numSwapsPerIndex[i]);

    printf("Total Swap Count: %d\n", totalSwapsCnt);
    printf("Sorted Array:\n\t");
    printArray(arr, len);

    free(numSwapsPerIndex);
}

void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
