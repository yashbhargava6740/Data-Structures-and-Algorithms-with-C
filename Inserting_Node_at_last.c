#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void insertNode(struct Node *head, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> next = head;
    struct Node *p = head;
    do {
        p = p -> next;
    } while(p -> next != head);
    p -> next = ptr;
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
    
    printf("Before Inserting Node:- ");
    getArr(head);
    printf("\n");
    insertNode(head, 40);
    printf("After Inserting Node:- ");
    getArr(head);
    free(head);
    free(second);
    free(third);
}