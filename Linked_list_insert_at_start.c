#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void getArr(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node *insertNode(struct Node *ptr, struct Node *ptr1) {
    ptr -> next = ptr1;
    return ptr;
}

void main() {
    struct Node *head,*second,*third,*new;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    new = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    new -> data = 40;

    printf("Before Inserting Node:- \n");
    getArr(head);

    printf("\n");

    head = insertNode(new,head);

    printf("After Inserting node:- \n");
    getArr(head);

    free(head);
    free(second);
    free(third);
    free(new);

}