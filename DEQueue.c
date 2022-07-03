// Restricted Input
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear, size;
    int *arr;
};
typedef struct queue q;

int isEmpty(q *queue) {
    if(queue -> front == queue -> rear) 
        return 1;
    return 0;
}

int isFull(q *queue) {
    if(queue -> rear == queue -> size - 1)
        return 1;
    return 0;
}

void enqueue(q *queue, int data) {
    if(isFull(queue))
        printf("Queue is Full!\n"); 
    else if(queue -> front == -1 && queue -> rear == -1) {
        queue -> front = queue -> rear = 0;
        queue -> arr[queue -> rear] = data;
    }
    else {
        queue -> arr[++queue -> rear] = data;
    }
}

int dequeueF(q *queue) {
    int val = -1;
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    else 
        val =  queue -> arr[queue -> front++];
    return val;
}

int dequeueR(q *queue) {
    int val = -1;
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    else 
        val =  queue -> arr[queue -> rear--];
    return val;
}

int peek(q *queue, int pos) {
    int val = -1;
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    else 
        val =  queue -> arr[pos-1];
    return val;
}

void traverseQueue(q *queue) {
    int ind = queue -> front;
    while(printf("%d ", queue -> arr[ind++]), ind <= queue -> rear);
    printf("\n");
}

void main() {
    q *queue = (q*)malloc(sizeof(q));
    queue -> rear = queue -> front = -1;
    queue -> size = 10;
    queue -> arr = (int*)malloc(queue -> size * sizeof(int));
    for(int i = 0; i < 10; i++)
        enqueue(queue, i);
    traverseQueue(queue);
    printf("Dequeued from front : %d\n", dequeueF(queue));
    printf("Dequeued from rear : %d\n", dequeueR(queue));
    printf("Dequeued from front : %d\n", dequeueF(queue));
    printf("Dequeued from rear : %d\n", dequeueR(queue));
    printf("Dequeued from front : %d\n", dequeueF(queue));
    printf("Dequeued from rear : %d\n", dequeueR(queue));
}