#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int top;
    char *array;
};

int isEmpty(struct stack *ptr) {
    if(ptr -> top == -1) {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char value) {
    ptr -> array[++(ptr -> top)] = value;
}

char pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        //printf("Underflow!\n");
        return '0';
    }
    return ptr -> array[--(ptr -> top)];
}

void main() {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st -> top = -1;
    char arr[1000], out;
    printf("Enter Expression!\n");
    scanf("%[^\n]%*c", arr);
    int ln = 0;
    while(ln++, arr[ln]);
    st -> array = (char *)malloc(ln*sizeof(char));

    for(int i = 0; arr[i]; i++) {
        if(arr[i] == '(') {
            push(st,arr[i]);
            //printf("pushing : %d ", st -> top);
        }
        else if(arr[i] == ')') {
            out = pop(st);
            //printf(" popping : %d ", st -> top);
            if(out == '0') {
                break;
            }
        }
    }
    if(st -> top == -1) 
        printf("Valid Parenthesis!\n");
    
    else 
        printf("Invalid Parenthesis!\n");
}