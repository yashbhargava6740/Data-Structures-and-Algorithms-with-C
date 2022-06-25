#include <stdio.h>

// First Method
/*int checkPrime(int nm) {
    static int divisor = 2;
    if((nm % divisor == 0 || nm == 1) && nm != 2) 
        return 0;
    if(divisor >= nm / 2 || nm == 2) 
        return 1;
    divisor++;
    return checkPrime(nm);
}*/


// Second Method
int checkPrime(int nm, int divisor) {
    if((nm % divisor == 0 || nm == 1) && nm != 2) 
        return 0;
    if(divisor >= nm / 2 || nm == 2) 
        return 1;
    return checkPrime(nm, divisor+1);
}

// Main Function
void main() {
    int n;
    printf("Enter Number:- ");
    scanf("%d", &n);
    int out = checkPrime(n, 2);
    printf("%d", out);
}
