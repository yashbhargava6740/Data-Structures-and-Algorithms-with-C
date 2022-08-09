#include <iostream>
using namespace std;

int getTerm(int n) {
    if(n == 0 || n == 1)
        return n;
    return getTerm(n-1) + getTerm(n-2);
}
int main() {
    int n, out;
    cin >> n;
    out = getTerm(n);
    cout << out << endl;
}