#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n)                // Logic for Hollow Square
                cout << "*"; 
            else if(i <= (n >> 1) + 1 && j == ((n+1) >> 1)-i+2 || j == (n >> 1) + i - 1)   // Logic for first half of Hollow Kite
                cout << "*";   
            else if(i > (n >> 1) + 1 && j == i - (n >> 1) + 1 || j == n - (i - (n >> 1))) // Logic for second half of Hollow Kite
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}