#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void countSort(int *arr, int n) {
    int mx = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr+i) > mx) 
            mx = *(arr+i);
    }
    
    int *count_arr = (int*)calloc(mx+1, sizeof(int));
    
    for(int i = 0; i < n; i++) {
        *(count_arr + *(arr+i)) += 1;
    }

    for(int i = 1; i < mx+1; i++) {
        *(count_arr+i) += *(count_arr+i-1);
    }

    int *sorted_arr = (int*)malloc((n) * sizeof(int));
    for(int i = 0; i < n; i++) {
        *(sorted_arr + *(count_arr+ *(arr+i)) - 1) = *(arr+i);
        *(count_arr+ *(arr+i)) -= 1;
    }
   
    for(int i = 0; i < n; i++) {
        *(arr+i) = *(sorted_arr+i);
    }
    free(sorted_arr);
    free(count_arr);
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
    countSort(arr, n);
    printf("After Sorting:- ");
    printArray(arr,n);
    free(arr);
}