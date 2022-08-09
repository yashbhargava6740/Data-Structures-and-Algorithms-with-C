#include <iostream>
using namespace std;

void replace(string st, int n, int i) { 
    if(i > n-1) 
        return;
    else if(st[i] == 'p' && st[i+1] == 'i') { 
        cout << "3.14";
        replace(st,n,i+2);
    }
    else {
        cout << st[i];
        replace(st,n,i+1);
    }
}

int main() {
    int n;
    string st;
    cin >> n >> st;
    replace(st,n,0);
    return 0;
}