#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mid = (n >> 1) + 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == mid || j == mid || j == i || j == n-i+1)
                cout << "* ";
            else   
                cout << "  "; 
        }
        cout << endl;
    }
}