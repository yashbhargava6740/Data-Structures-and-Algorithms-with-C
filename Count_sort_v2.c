#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void countSort(int *arr, int n) {
    int mx = *arr, i = 0, j = 0;
    for(int i = 1; i < n; i++) {
        if(*(arr+i) > mx) 
            mx = *(arr+i);
    }
    int *count_arr = (int*)calloc(mx+1, sizeof(int));
    
    for(int i = 0; i < n; i++) {
        *(count_arr + *(arr+i)) += 1;
    }

    while(i <= mx) {
        if(*(count_arr + i) > 0) {
            *(arr+j) = i;
            *(count_arr + i) -= 1;
            j++;
        }
        else   
            i++;
    }
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