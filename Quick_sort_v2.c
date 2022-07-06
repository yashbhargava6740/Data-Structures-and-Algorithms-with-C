#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot,i,j;
    pivot = *(arr+low);
    i = low+1;
    j = high;
    do {
    while(*(arr+i) <= pivot) 
        i++;
    while(*(arr+j) > pivot) 
        j--;
    if(i < j)
       swap(arr+i, arr+j);
    }while(i < j);
    
    swap(arr+low, arr+j);
    return j;
}
void quickSort(int *arr,int low, int high) {
    int partitionIndex;
    if(low < high) {
        partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1, high);
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
    quickSort(arr,0, n-1);
    printf("After Sorting:- ");
    printArray(arr,n);
    free(arr);
}