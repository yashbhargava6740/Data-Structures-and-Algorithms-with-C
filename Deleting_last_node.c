#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *previous;
    struct Node *next;
};


void delNode(struct Node *head) {
    struct Node *ptr = head -> next, *p = head;
    while(ptr -> next != NULL) {
        ptr = ptr -> next;
        p = p -> next;
    }
    p -> next = NULL;
    free(ptr);
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
    printf("Before Deleting Node:- ");
    getArr(head);
    printf("\n");
    delNode(head);
    printf("After Deleting Node:- ");
    getArr(head);
    

}