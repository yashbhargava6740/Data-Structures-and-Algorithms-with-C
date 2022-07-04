#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void selectionSort(int *arr, int n) {
    int min,i,j;
    for(i = 0; i < n; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(*(arr+j) < *(arr + min)) {
                min = j;
            }
        }
        int temp = *(arr+i);
        *(arr+i) = *(arr+min);
        *(arr+min) = temp;
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
    selectionSort(arr,n);
    printf("After Sorting array:- ");
    printArray(arr,n);    
    free(arr);
}
