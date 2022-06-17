#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node * insertNode(struct Node *head, int value) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = value;
    struct Node *p = head;
    do{
        p = p -> next;
    } while((p -> next) != head);

    ptr -> next = head;
    p -> next = ptr;
    return ptr;
}

void getArr(struct Node *head) {
    struct Node *ptr = head;
    do {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    } while(ptr != head);
}

void main() {
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    (*head).data = 10;
    (*head).next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = head;
    printf("Before Inserting Node:- ");
    getArr(head);
    printf("\n");
    head = insertNode(head, 15);
    printf("After Inserting Node:- ");                // Inserting Node with value 15 at first
    getArr(head);
    free(head);
    free(second);
    free(third);
}