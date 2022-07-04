#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insertionSort(int *arr, int n) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = *(arr+i);
        j = i-1;
        while(j >= 0 && key < *(arr+j)) {
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = key;
    }
}

void main() {
    int *arr,n;
    printf("Enter Size of Array:- ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Enter Elements:- ");
    for(int i = 0; i < n; i++) 
        scanf("%d", arr+i);

    printf("Before sorting Array:- ");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("After Sorting array:- ");
    printArray(arr,n);    
}