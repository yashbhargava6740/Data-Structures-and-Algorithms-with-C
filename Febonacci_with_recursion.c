#include <stdio.h>

void febo(int a, int b, int c, int d) {
    if(!(d == 0)) {
        printf("%d ", c);
        febo(b, c, b+c, d-1);    
    }
    
}

void main() {
    int a = 0, b = 1;
    int n;
    printf("Enter Number Of Terms:- ");
    scanf("%d", &n);
    if(n == 1)
        printf("%d", a);
    else if(n == 2)
        printf("%d %d ", a,b);
    else {
        printf("%d %d ", a,b);
        febo(a,b,a+b,n-2);
    }
    
}