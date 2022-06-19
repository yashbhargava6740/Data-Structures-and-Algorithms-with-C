#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    if(ptr -> top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if(ptr -> top == ptr -> size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct stack *ptr, int val) {
    if(isFull(ptr)) 
        printf("Stack Overflow! cannot push %d\n", val);
    else
        ptr -> arr[++(ptr -> top)] = val;
}

int pop(struct stack *ptr) {
    if(isEmpty(ptr)) 
        printf("Stack Underflow\n");
    else {
    int val = ptr -> arr[ptr -> top];
    (ptr -> top)--;
    return val;
    }
}

void getStack(struct stack *ptr) {
    for(int i = 0; i <= ptr -> top; i++) {
        printf("%d ", *(ptr->arr + i));
    }
}

int peek(struct stack *ptr, int position) {
    int index = ptr -> top - position + 1;
    if(index < 0) {
        printf("Invalid Postion!\n");
        return 0;
    }
    else
        return ptr -> arr[index];
    
}

int stackTop(struct stack *ptr) {
    if(!isEmpty(ptr))
        return ptr -> arr[ptr -> top];

    else{
        printf("Stack Underflow!\n");
        return 0;
    }
}

int stackBottom(struct stack *ptr) {
    if(!isEmpty(ptr))
        return ptr -> arr[0];
    else {
        printf("Stack Underflow!\n");
        return 0;
    }
}
void main() { 
    struct stack *s1 = (struct stack*)malloc(sizeof(struct stack));
    s1 -> size = 5;
    s1 -> top = -1;
    s1 -> arr = (int *)malloc(s1 -> size * sizeof(int));
    // Pushing Elements
    push(s1,5);
    push(s1,10);
    push(s1,15);
    push(s1,20);
    push(s1,25);

    // Overflow Case
    push(s1, 30);

    // Popping ELement
    int out = pop(s1);
    printf("Popped : %d\n", out);

    // Peek Operation
    int out1 = peek(s1, 4);      // 4 Element of stack
    if(out1)
        printf("Elemnt at %d position is %d\n",4, out1);
    
    // Stack Top
    int out2 = stackTop(s1);
    if(out2) {
        printf("Stack Top : %d\n", out2);
    }
    
    // Stack Bottom
    int out3 = stackBottom(s1);
    if(out3) {
        printf("Stack Bottom : %d\n", out3);
    }
    // Printing all Elements after performing operations
    getStack(s1);
    free(s1);   

}