#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traverseList(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertNode(struct Node *ptr1,struct Node *ptr2,struct Node *ptr3) {
    ptr1 -> next = ptr3;
    ptr3 -> next = ptr2;
    ptr2 -> next = NULL;
}

void main() {
    struct Node *head, *second, *third, *second_new;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    second_new = (struct Node *)malloc(sizeof(struct Node));
    head -> data = 10;
    head -> next = second;
    second -> data = 20;
    second -> next = third;
    third -> data = 30;
    third -> next = second_new;
    second_new -> data = 40;
    second_new -> next = NULL;

    printf("Before Inserting Node:- \n");
    traverseList(head);

    printf("\n");
    insertNode(second,third,second_new);

    printf("After Inserting Node:- \n");
    traverseList(head);

}
