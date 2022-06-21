#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr) {
    if(ptr == NULL) {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr) {
    if(ptr == NULL) {
        return 1;
    } 
    return 0;
}

struct Node *push(struct Node *ptr, int value) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(isFull(p)) {
        printf("Stack Overflow!\n");
        return NULL;
    }
    p -> next = ptr;
    p -> data = value;
    ptr = p;
    return ptr;
}

int pop(struct Node **ptr) {
    struct Node **p = ptr;
    int val = (*ptr) -> data;
    *ptr = (*ptr) -> next;
    free(*p);
    return val;
}

int peek(struct Node *ptr, int position) {
    position--;
    while(position--) {
        ptr = ptr -> next;
    }
    return ptr -> data;
}

void getArr(struct Node *ptr) {
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    
}

int stackTop(struct Node *ptr) {
    return ptr -> data;
}

int stackBottom(struct Node *ptr) {
    while(ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    return ptr -> data;
}

void main() {
    struct Node *top = NULL;
    int ch = 0;
    A:
        printf("Stack Operations:- \n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Stack_Top\n5. Stack_Bottom\n6. Print Array\n7. Exit\n");
        printf("Enter Your Choice:- \n");
        scanf("%d", &ch);
        switch(ch) {

        case 1:
            printf("Enter Value to push:- ");
            int val;
            scanf("%d", &val);
            top = push(top, val);
            if(top != NULL)
                printf("Value Pushed!\n\n");
            goto A;
        
        case 2: 
            if(isEmpty(top)) {
                printf("Stack Undeflow!\n");
            }
            else {
            int out = pop(&top);
            printf("***Popped Value : %d***\n\n", out);
            }
            goto A;

        case 3: 
            int pos;
            printf("Enter Position:- ");
            scanf("%d", &pos);
            int out1 = peek(top, pos);
            printf("***Value at %d position : %d***\n\n",pos, out1);
            goto A;
        
        case 4: 
            int out2 = stackTop(top);
            printf("***StackTop : %d***\n\n", out2);
            goto A;

        case 5: 
            int out3 = stackBottom(top);
            printf("***StackBottom : %d***\n\n", out3);
            goto A;

        case 6: 
            getArr(top);
            printf("\n\n");
            goto A;

        case 7:
            goto B;
        
        default:
            printf("Entered Wrong Choice\n ");
            goto A;
    }
    B:
        getArr(top);
        printf("\n");
        printf("Exited...... ");
    free(top);
}