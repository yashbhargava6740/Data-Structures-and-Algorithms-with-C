#include <iostream>
using namespace std;

int main() {
    int n = 11;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < 2*n; j++) {
            if(i == 1 && j != (n) || i == n || j == 1 || j == 2*n-1)
                cout << "*";
            else if(i == 1 && (j == n))
                cout << "|";
            else if(j == n-i+1) {
                cout << "/";
            }
            else if(j == n+i-1) {
                cout << "\\";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}