#include <stdio.h>
#include <stdlib.h>

void printArray(float *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%g ", *(arr + i));
    }
    printf("\n");
}

void printStack(float *arr, int n) {
    for(int i = 0; i <= n; i++) {
        printf("%g ", *(arr + i));
    }
    printf("\n");
}

struct stack {
    int top;
    float array[10];
};

void insertionSort(float *arr, int n){
    int key;
    for(int i = 1; i <= n; i++) {
        float ele = *(arr+i);
        key = i-1;
        while(ele < *(arr+key) && key >= 0) {
            *(arr+key+1) = *(arr+key);
            key--;
        }
        *(arr + key + 1) = ele;
    }
}

void bucketSort(float *arr, int n) {
    struct stack st[n];
    int index;
    for(int i = 0; i <= n; i++) {
        st[i].top = -1;
    }
    for(int i = 0; i < n; i++) {
        index = *(arr+i);
        st[index].array[++st[index].top] = *(arr + i);   
    }
    
    for(int i = 0; i <= n; i++) {
        insertionSort(st[i].array, st[i].top);
    }
    
    /*for(int i = 0; i <= n; i++) {
        printStack(st[i].array, st[i].top);
    }*/
    
    int i = 0, j = 0,k = 0;
    while(i <= n) {
        if(st[i].top != -1) {
            *(arr+k) = st[i].array[j];
            j++;
            k++;
            st[i].top -= 1;
        }
        else {
            j = 0;
            i++;
        }
    }
}

void main() {
    int n;
    printf("Enter Size of array:- ");
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));
    printf("Enter Elements:- \n");
    for(int i = 0; i < n; i++) {
        scanf("%f", arr+i);
    }
    printf("Before Sorting:- ");
    printArray(arr,n);
    bucketSort(arr, n);
    printf("After Sorting:- ");
    printArray(arr,n);
    free(arr);
}