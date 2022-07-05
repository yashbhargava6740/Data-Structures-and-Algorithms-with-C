// Merge Sort For Ascending Order

#include <stdio.h>
#include <stdlib.h>
int n;
void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
void mergeArray(int *arr,int low,int mid,int high) {
    int i = low, j = mid+1, k = low, temp[n];
    while(i <= mid && j <= high) {
        if(*(arr+i) < *(arr+j)) {
            *(temp+k) = *(arr+i);
            i++;
            k++;
        }
        else {
            *(temp+k) = *(arr+j);
            j++;
            k++;
        }
    }
    while(i <= mid) {
        *(temp+k) = *(arr+i);
        k++;
        i++;
    }
    while(j <= high) {
        *(temp+k) = *(arr+j);
        k++;
        j++;
    }
    for(i = low; i <= high; i++) {
        *(arr+i) = *(temp+i);
    }
}   

void mergeSort(int *arr, int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeArray(arr,low,mid,high);
    }
}

void main() {
    int *arr;
    printf("Enter Size of Array:- ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Enter Elements:- ");
    for(int i = 0; i < n; i++) 
        scanf("%d", arr+i);

    printf("Before sorting Array:- ");
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printf("After Sorting array:- ");
    printArray(arr,n);    
    free(arr);
}