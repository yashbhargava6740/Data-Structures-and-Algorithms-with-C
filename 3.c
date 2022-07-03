#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

int isEmpty(node *f) {
    if(f == NULL) 
        return 1;
    return 0;
}

int isFull(node *ptr) {
    if(ptr == NULL) 
        return 1;
    return 0;
}

int peek(node *ptr, int pos) {
    while(--pos) 
        ptr = ptr -> next;
    return ptr -> data;
}

void enqueue(node **front, node **rear, int val) {
    node *n = (node*)malloc(sizeof(node));
    if(isFull(n))
        printf("Queue is Full!\n");
    else {
        n -> data = val;
        n -> next = NULL;
        if(*front == NULL && *rear == NULL) {
            *front = *rear = n;
        }
        else {
            (*rear) -> next = n;
            *rear = n;
        }
    }
    //printf("%d %d", front -> data, rear -> data);
}

int dequeue(node **front) {
    int val = -1;
    if(isEmpty(*front))
        printf("Queue is empty!\n");
    else {
        val = (*front) -> data;
        *front = (*front) -> next;
    }
    return val;
}

void traverseLinkedList(node *ptr) {
    if(isEmpty(ptr)) 
        printf("Queue is empty!\n");
    else
        while(ptr != NULL) {
            printf("%d ", ptr -> data);
            ptr = ptr -> next;
        }   
}

void main() {
    node *front, *rear;
    front = rear = NULL;
    for(int i = 0; i < 10; i++)
        enqueue(&front, &rear, i);
    printf("Dequeued : %d\n", dequeue(&front));
    traverseLinkedList(front);

    printf("\n");
    printf("Value at %d position is %d", 3, peek(front, 3));
}