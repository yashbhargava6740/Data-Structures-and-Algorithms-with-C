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

struct Node  *delNode(struct Node * head) {
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

void main() {
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    getArr(head);
    printf("\n");
    head = delNode(head);
    getArr(head);

    free(head);
    free(second);
    free(third);
}