#include <stdio.h>
#include <stdlib.h>

struct queue 
{
    int front, rear, size;
    int *arr;
};

int isEmpty(struct queue *p) {
    if(p -> front == p -> rear) {
        return 1;
    }
    return 0;
}

int isFull(struct queue *p) {
    if(p -> rear == p -> size-1) {
        return 1;
    }
    return 0;
}


void enqueue(struct queue *p, int data) {
    if(!isFull(p)) {
        p -> rear++;
        p -> arr[p -> rear] = data;
    }
    else 
        printf("Queue is Full!\n");
} 

int dequeue(struct queue *p) {
    if(!isEmpty(p))
        return(p -> arr[++p -> front]);
    else {
        printf("Queue is Empty!\n");
        return -1;
    }
}

int peek(struct queue *p, int pos) {
    if(pos - 1 < 0) 
        printf("Position not valid\n");
    else
        return p -> arr[pos - 1];
}

void main() {
    struct queue *ptr = (struct queue*)malloc(sizeof(struct queue));
    ptr -> size = 10;
    ptr -> front = -1;
    ptr -> rear = -1;
    ptr -> arr = (int *)malloc(ptr -> size * sizeof(int));
    for(int i = 1; i <= 10; i++)
        enqueue(ptr, i);
    if(isEmpty(ptr)) {
        printf("Queue is Empty!\n");
    }
    if(isFull(ptr)) {
        printf("Queue is Full!\n");
    }
    //printf("Element : %d\n", peek(ptr, 3));
}