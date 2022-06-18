#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *previous;
    struct Node *next;
};


void insertNode(struct Node *head, int value , int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = value;
    while(--index) {
        head = head -> next;
    }

    ptr -> next = head -> next;
    (head -> next) -> previous = ptr;
    ptr -> previous = head;
    head -> next = ptr;
}

void getArr(struct Node *head) {
    do {
        printf("%d ", head -> data);
        head = head -> next;
    } while(head -> next != NULL);
    printf("%d", head -> data);
    printf("\n");
    
    do {
        printf("%d ", head -> data);
        head = head -> previous;
    } while(head != NULL);
}



void main() {
    struct Node *head, *second, *third, *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head -> previous = NULL;
    head -> next = second;
    head -> data = 10;

    second -> previous = head;
    second -> next = third;
    second -> data = 20;

    third -> previous = second;
    third -> next = fourth;
    third -> data = 30;

    fourth -> previous = third;
    fourth -> next = NULL;
    fourth -> data = 40;
    printf("Before Adding Node:- ");
    getArr(head);
    printf("\n");
    insertNode(head, 12,2);
    printf("After Adding Node:- ");
    getArr(head);
    

}