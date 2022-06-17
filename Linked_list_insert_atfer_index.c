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

void setArr(int index, int value, struct Node *ptr) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p -> data = value;
    while(--index) {
        ptr = ptr -> next;
    } 
    p -> next = ptr -> next;
    ptr -> next = p;

}

void main() {
    struct Node *head, *second, *third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;
    
    int index, value;
    printf("Enter Node Index and value: ");
    scanf("%d%d", &index, &value);

    getArr(head);
    setArr(index, value, head);

    printf("\n");
    getArr(head);
    free(head);
    free(second);
    free(third);
}