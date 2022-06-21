#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *ptr, int value) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p -> next = ptr;
    p -> data = value;
    ptr = p;
    return ptr;
}

struct Node *pop(struct Node*ptr) {
    struct Node *p = ptr;
    int val = ptr -> data;
    ptr = ptr -> next;
    free(p);
    return ptr;
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
        if(ch == 1) {
            printf("Enter Value to push:- ");
            int val;
            scanf("%d", &val);
            top = push(top, val);
            printf("Value Pushed!\n\n");
            goto A;
        }
        else if(ch == 2) {
            int out = top -> data;
            top = pop(top);
            printf("***Popped Value : %d***\n\n", out);
            goto A;
        }

        else if(ch == 3) {
            int pos;
            printf("Enter Position:- ");
            scanf("%d", &pos);
            int out = peek(top, pos);
            printf("***Value at %d position : %d***\n\n",pos, out);
            goto A;
        }

        else if(ch == 4) {
            int out = stackTop(top);
            printf("***StackTop : %d***\n\n", out);
            goto A;
        }

        else if(ch == 5) {
            int out = stackBottom(top);
            printf("***StackBottom : %d***\n\n", out);
            goto A;
        }

        else if(ch == 6) {
            getArr(top);
            printf("\n\n");
            goto A;
        }

        else {
            goto B;
        }
        B:
            getArr(top);
            printf("\n");
            printf("Exited...... ");
    free(top);
}