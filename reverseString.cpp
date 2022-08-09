#include <iostream>
using namespace std;

void reverse(string st, int n) {
    if(n == -1) 
        return;
    cout << st[n];
    reverse(st,n-1);
}

int main() {
    int ln;
    string st;
    cin >> ln >> st;
    reverse(st, ln-1);
    return 0;
}