// Restricted Output

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

void traverseQueue(q *queue) {
    int ind = 0;
    while(printf("%d ", queue -> arr[ind++]), ind <= queue -> rear);
    printf("\n");
}

void enqueueR(q *queue, int data) {
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

void enqueueF(q *queue, int data) {
    if(isFull(queue))
        printf("Queue is Full!\n"); 
    else if(queue -> front == -1 && queue -> rear == -1) {
        queue -> front = queue -> rear = 0;
        queue -> arr[queue -> rear] = data;
    }
    else {
        int ind = queue -> rear;
        while(queue -> arr[ind + 1] = queue -> arr[ind], ind--, ind >= queue -> front);
        queue -> arr[queue -> front++] = data;
        queue -> rear++;
    }
}

int dequeue(q *queue) {
    int val = -1;
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    else 
        val =  queue -> arr[queue -> front++];
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

void main() {
    q *queue = (q*)malloc(sizeof(q));
    queue -> rear = queue -> front = -1;
    queue -> size = 20;
    queue -> arr = (int*)malloc(queue -> size * sizeof(int));
    for(int i = 0; i < 10; i++)
        enqueueR(queue, i);
    for(int i = 10; i < 20; i++)
        enqueueF(queue, i);
    traverseQueue(queue);
    
}