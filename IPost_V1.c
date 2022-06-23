#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int top;
    char *array;
    int size;
};

char pop(struct stack *ptr) {
    return ptr -> array[(ptr -> top)--];
}

void push(struct stack *ptr, char data) {
    ptr -> array[++(ptr -> top)] = data;
}

char stackTop(struct stack *ptr) {
    return ptr -> array[ptr -> top];
}

int isOperator(char a) {
    if(a == '+' || a == '-' || a == '*' || a == '/') 
        return 1;
    return 0;
} 

int precedence(char a) {
    if(a == '*' || a == '/')
        return 2;
    if(a == '+' || a == '-')
        return 1; 
    return 0;
}

char *infixToPostfix(char a[]) {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st -> top = -1;
    st -> size = 100;
    st -> array = (char *)malloc(st -> size * sizeof(char));
    int ln = 0, i = 0, ind = 0;
    while(ln++, a[ln]);
    char *postFix = (char *)malloc((ln+1) * sizeof(char));
    for(i; a[i]; i++) {
        if(!isOperator(a[i])) {
            postFix[ind++] = a[i];
        }
        else {
            if(precedence(stackTop(st)) < precedence(a[i])) {
                push(st, a[i]);
            }
            else {
                while(precedence(stackTop(st)) >= precedence(a[i])) {
                    postFix[ind++] = pop(st);
                }
                push(st,a[i]);
            }
        }
    }
    while(st -> top != -1) {
        postFix[ind++] = pop(st);
    }
        
    postFix[ind++] = '\0';
    return postFix;
}

void main() {
    char string[1000];
    scanf("%[^\n]%*c", string);
    char *out = infixToPostfix(string);
    printf("%s", out);
}