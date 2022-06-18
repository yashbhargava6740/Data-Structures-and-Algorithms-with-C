#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void delNode(struct Node *head, int index) {
    struct Node *ptr = head, *p;
    p = head -> next;
    while(--index) {
        ptr = ptr -> next;
        p = p -> next;
    }
    ptr -> next = p -> next;
    free(p);
}

void getArr(struct Node *head) {
    struct Node *ptr = head;
    /*while(ptr -> next != head) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("%d", ptr -> data);*/

    do {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }while(ptr != head);
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
    
    printf("Before Deleting Node:- ");
    getArr(head);
    printf("\n");

    delNode(head, 2);
    
    printf("After Deleting First Node:- ");
    getArr(head);
    free(head);
    free(second);
    free(third);
}