#include <iostream>
using namespace std;

int main() {
    int n;  //41
    cin >> n;
    int mid = (n >> 1) + 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == mid || j == mid || (i == 1 && j >= mid) || (i <= mid && j == 1) || (i >= mid && j == n) || (i == n && j <= mid))
                cout << "* ";
            else 
                cout << "  ";
        }
        cout << endl;
    }
}