#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void getArr(struct Node *head) {
    while(head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
}

void delNode(struct Node *head, int index) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    while(--index) {
        head = head -> next;
        ptr = head -> next;
    }
    head -> next = ptr -> next;
    free(ptr);
}

void main() {
    struct Node *head, *second, *third, *fourth;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = fourth;

    fourth -> data = 40;
    fourth -> next = NULL;

    getArr(head);
    //printf("\n%d\n", third -> data);
    delNode(head, 2);
    getArr(head);
    //printf("\n%d", third -> data);

    free(head);
    free(second);
    free(third);
    free(fourth);
}