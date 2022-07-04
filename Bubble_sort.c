#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int *arr, int n) {
    int isSorted = 0;
    for(int i = 0; i < n - 1; i++) {
        isSorted = 1;
        for(int j = 0; j < n - 1 - i; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                isSorted = 0;
            }
        }
        if(isSorted) 
            return;
    }
}

void main() {
    int n;
    printf("Enter Size of array:- ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter Elements:- \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }
    printf("Before Sorting:- ");
    printArray(arr,n);
    bubbleSort(arr, n);
    printf("After Sorting:- ");
    printArray(arr,n);
}