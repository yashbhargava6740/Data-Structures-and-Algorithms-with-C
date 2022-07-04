#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int partition(int *arr, int low, int high) {
    int i = low+1,j = high;
    do {
        while(*(arr+i) <= *(arr+low)) {
            i++;
        }
        while(*(arr+j) > *(arr+low)) {
            j--;
        }
        if(i < j) {
            int temp = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = temp;
        }
    }while(i < j);
    int temp = *(arr+low);
    *(arr+low) = *(arr+j);
    *(arr+j) = temp;
    //printArray(arr,9);
    return j;

}
void quickSort(int *arr, int low, int high) {
    int partitionIndex;
    if(low < high) {
    partitionIndex = partition(arr,low,high);
    quickSort(arr,low,partitionIndex-1);
    quickSort(arr,partitionIndex+1, high);
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
    quickSort(arr,0,n-1);

    printf("After Sorting array:- ");
    printArray(arr,n);    
    free(arr);
}