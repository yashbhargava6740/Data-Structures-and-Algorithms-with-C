#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n) 
                cout << "* ";
            else if(i <= (n >> 1) + 1 && (j >= i && j <= n-i+1))
                cout << "* ";
            else if(i > (n >> 1) + 1 && (j <= i && j >= n-i+1))
                cout << "* ";
            else 
                cout << "  ";
        }
        cout << endl;
    }
}