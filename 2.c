#include <stdio.h>
#include <stdlib.h>

struct q 
{
    int front;
    int rear;
    int size;
    int *arr;
};

typedef struct q q;

void enqueue(q *ptr, int data) {
    ptr -> rear = (ptr -> rear + 1 )% ptr -> size;
    ptr -> arr[ptr -> rear] = data;
}   

int dequeue(q *ptr) {
    ptr -> front = (ptr -> front + 1) % ptr -> size;
    return ptr -> arr[ptr -> front];
}

void queueTraversal(q *ptr) {
    int ind = ptr -> rear, i = ptr -> front + 1;
    while(i <= ind) {
        printf("%d ", ptr -> arr[i]);
        i++;
    }
}

void main() {
    q *queue;
    queue = (q*)malloc(sizeof(q));
    queue -> size = 10;
    queue -> front = -1;
    queue -> rear = -1;
    queue -> arr = (int*)malloc(queue -> size * sizeof(int));
    for(int i = 0; i < 10; i++)
        enqueue(queue, i);
    dequeue(queue);
    dequeue(queue);
    queueTraversal(queue);
}

