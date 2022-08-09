#include <iostream>
using namespace std;

int gcd(int n1, int n2) {
    if(n1 % n2 == 0)
        return n2;
    return gcd(n2, n1 % n2);
}
int main() {
    int n1, n2, out;
    cin >> n1 >> n2;
    out = gcd(n1,n2);
    cout << out;
}